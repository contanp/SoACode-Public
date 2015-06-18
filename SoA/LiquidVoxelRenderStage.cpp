#include "stdafx.h"
#include "LiquidVoxelRenderStage.h"

#include <Vorb/graphics/GLProgram.h>
#include "Camera.h"
#include "NChunk.h"
#include "ChunkMeshManager.h"
#include "ChunkRenderer.h"
#include "GameRenderParams.h"
#include "MeshManager.h"
#include "SoaOptions.h"
#include "RenderUtils.h"
#include "ShaderLoader.h"

void LiquidVoxelRenderStage::hook(const GameRenderParams* gameRenderParams) {
    m_gameRenderParams = gameRenderParams;
}

void LiquidVoxelRenderStage::render(const Camera* camera) {
    ChunkMeshManager* cmm = m_gameRenderParams->chunkMeshmanager;
    const std::vector <ChunkMesh *>& chunkMeshes = cmm->getChunkMeshes();
    if (chunkMeshes.empty()) return;

    if (!m_program.isCreated()) {
        m_program = ShaderLoader::createProgramFromFile("Shaders/WaterShading/WaterShading.vert",
                                                             "Shaders/WaterShading/WaterShading.frag");
    }
    m_program.use();
    m_program.enableVertexAttribArrays();

    glUniform1f(m_program.getUniform("sunVal"), m_gameRenderParams->sunlightIntensity);

    glUniform1f(m_program.getUniform("FogEnd"), m_gameRenderParams->fogEnd);
    glUniform1f(m_program.getUniform("FogStart"), m_gameRenderParams->fogStart);
    glUniform3fv(m_program.getUniform("FogColor"), 1, &(m_gameRenderParams->fogColor[0]));

    glUniform3fv(m_program.getUniform("LightPosition_worldspace"), 1, &(m_gameRenderParams->sunlightDirection[0]));

    glUniform1f(m_program.getUniform("FadeDistance"), (GLfloat)soaOptions.get(OPT_VOXEL_RENDER_DISTANCE).value.f - 12.5f);

    float blockAmbient = 0.000f;
    glUniform3f(m_program.getUniform("AmbientLight"), blockAmbient, blockAmbient, blockAmbient);
    glUniform3fv(m_program.getUniform("LightColor"), 1, &(m_gameRenderParams->sunlightColor[0]));

    glUniform1f(m_program.getUniform("dt"), 1.0f);

    glActiveTexture(GL_TEXTURE6);
    //glBindTexture(GL_TEXTURE_2D, waterNormalTexture.id);
    glUniform1i(m_program.getUniform("normalMap"), 6);

    if (m_gameRenderParams->isUnderwater) glDisable(GL_CULL_FACE);
    glDepthMask(GL_FALSE);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NChunk::vboIndicesID);

    for (unsigned int i = 0; i < chunkMeshes.size(); i++) //they are sorted backwards??
    {
        ChunkRenderer::drawWater(chunkMeshes[i], m_program,
                          m_gameRenderParams->chunkCamera->getPosition(),
                          m_gameRenderParams->chunkCamera->getViewProjectionMatrix());
    }

    glDepthMask(GL_TRUE);
    if (m_gameRenderParams->isUnderwater) glEnable(GL_CULL_FACE);

    m_program.disableVertexAttribArrays();
    m_program.unuse();
}
