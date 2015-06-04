#include "stdafx.h"
#include "GameplayRenderPipeline.h"

#include <Vorb/graphics/GLStates.h>

#include "ChunkMemoryManager.h"
#include "ChunkMeshManager.h"
#include "Errors.h"
#include "GameSystem.h"
#include "MTRenderState.h"
#include "MeshManager.h"
#include "PauseMenu.h"
#include "SoAState.h"
#include "SoaOptions.h"
#include "SpaceSystem.h"
#include "soaUtils.h"

#define DEVHUD_FONT_SIZE 32

GameplayRenderPipeline::GameplayRenderPipeline() {
    // Empty
}

void GameplayRenderPipeline::init(const ui32v4& viewport, const SoaState* soaState, const App* app,
                                  const PDA* pda,
                                  SpaceSystem* spaceSystem,
                                  GameSystem* gameSystem,
                                  const PauseMenu* pauseMenu) {
    //// Set the viewport
    //m_viewport = viewport;

    //m_soaState = soaState;

    //// Grab mesh manager handle
    //m_meshManager = soaState->chunkMeshManager.get();

    //// Construct framebuffer
    //m_hdrFrameBuffer = new vg::GLRenderTarget(m_viewport.z, m_viewport.w);
    //m_hdrFrameBuffer->init(vg::TextureInternalFormat::RGBA16F, soaOptions.get(OPT_MSAA).value.i, vg::TextureFormat::RGBA, vg::TexturePixelType::HALF_FLOAT).initDepth();
    //if (soaOptions.get(OPT_MSAA).value.i > 0) {
    //    glEnable(GL_MULTISAMPLE);
    //} else {
    //    glDisable(GL_MULTISAMPLE);
    //}

    //// Make swap chain
    //m_swapChain = new vg::RTSwapChain<2>();
    //m_swapChain->init(m_viewport.z, m_viewport.w, vg::TextureInternalFormat::RGBA8);
    //m_quad.init();

    //// Get window dimensions
    //f32v2 windowDims(m_viewport.z, m_viewport.w);

    //m_spaceCamera.setAspectRatio(windowDims.x / windowDims.y);
    //m_localCamera.setAspectRatio(windowDims.x / windowDims.y);

    //// Register Stages
    //registerStage(&stages.skybox);
    //registerStage(&stages.opaqueVoxel);
    //registerStage(&stages.cutoutVoxel);
    //registerStage(&stages.chunkGrid);
    //registerStage(&stages.transparentVoxel);
    //registerStage(&stages.liquidVoxel);
    //registerStage(&stages.devHud);
    //registerStage(&stages.pda);
    //registerStage(&stages.pauseMenu);
    //registerStage(&stages.nightVision);
    //registerStage(&stages.hdr);
    //registerStage(&stages.spaceSystem);

    //// Init Stages
    //stages.skybox.init(&m_spaceCamera, &soaState->texturePathResolver);
    //stages.opaqueVoxel.init(&m_gameRenderParams);
    //stages.cutoutVoxel.init(&m_gameRenderParams);
    //stages.chunkGrid.init(&m_gameRenderParams);
    //stages.transparentVoxel.init(&m_gameRenderParams);
    //stages.liquidVoxel.init(&m_gameRenderParams);
    //stages.devHud.init("Fonts\\chintzy.ttf", DEVHUD_FONT_SIZE, app, windowDims);
    //stages.pda.init(pda);
    //stages.pauseMenu.init(pauseMenu);
    //stages.nightVision.init(&m_quad);
    //stages.hdr.init(&m_quad, &m_localCamera);
    //stages.spaceSystem.init(soaState, ui32v2(windowDims),
    //                        nullptr, &m_spaceCamera,
    //                        &m_localCamera);

    //loadNightVision();

    //// No post-process effects to begin with
    //stages.nightVision.setActive(false);
    //stages.chunkGrid.setActive(false);
}

void GameplayRenderPipeline::setRenderState(const MTRenderState* renderState) {
    m_renderState = renderState;
}

GameplayRenderPipeline::~GameplayRenderPipeline() {
    destroy(true);
}

void GameplayRenderPipeline::render() {
    //const GameSystem* gameSystem = m_soaState->gameSystem.get();
    //const SpaceSystem* spaceSystem = m_soaState->spaceSystem.get();

    //updateCameras();
    //// Set up the gameRenderParams
    //const GameSystem* gs = m_soaState->gameSystem.get();

    //// Get the physics component
    //auto& phycmp = gs->physics.getFromEntity(m_soaState->playerEntity);
    //VoxelPosition3D pos;
    //if (phycmp.voxelPositionComponent) {
    //    pos = gs->voxelPosition.get(phycmp.voxelPositionComponent).gridPosition;
    //}
    //m_gameRenderParams.calculateParams(m_spaceCamera.getPosition(), &m_localCamera,
    //                                   pos, 100, m_meshManager, false);
    //// Bind the FBO
    //m_hdrFrameBuffer->use();
  
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //// worldCamera passes
    //stages.skybox.render();

    //if (m_wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //stages.spaceSystem.setShowAR(false);
    //stages.spaceSystem.setRenderState(m_renderState);
    //stages.spaceSystem.render();

    //if (m_voxelsActive) {
    //    glClear(GL_DEPTH_BUFFER_BIT);
    //    glEnable(GL_BLEND);
    //    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //    stages.opaqueVoxel.render();
    //    // _physicsBlockRenderStage->draw();
    //    //  m_cutoutVoxelRenderStage->render();

    //    auto& voxcmp = gameSystem->voxelPosition.getFromEntity(m_soaState->playerEntity).parentVoxelComponent;
    //    stages.chunkGrid.setChunks(spaceSystem->m_sphericalVoxelCT.get(voxcmp).chunkMemoryManager);
    //    stages.chunkGrid.render();
    //    //  m_liquidVoxelRenderStage->render();
    //    //  m_transparentVoxelRenderStage->render();
    //}
    //if (m_wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //// Check for face transition animation state
    //if (stages.spaceSystem.needsFaceTransitionAnimation) {
    //    stages.spaceSystem.needsFaceTransitionAnimation = false;
    //    m_increaseQuadAlpha = true;
    //    m_coloredQuadAlpha = 0.0f;
    //}

    //// Render last
    //glBlendFunc(GL_ONE, GL_ONE);
    //stages.spaceSystem.renderStarGlows(f32v3(1.0f));
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //// Post processing
    //m_swapChain->reset(0, m_hdrFrameBuffer->getID(), m_hdrFrameBuffer->getTextureID(), soaOptions.get(OPT_MSAA).value.i > 0, false);

    //// TODO: More Effects
    //if (stages.nightVision.isActive()) {
    //    stages.nightVision.render();
    //    m_swapChain->swap();
    //    m_swapChain->use(0, false);
    //}

    //// Draw to backbuffer for the last effect
    //glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //glDrawBuffer(GL_BACK);
    //glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    //glActiveTexture(GL_TEXTURE1);
    //glBindTexture(m_hdrFrameBuffer->getTextureTarget(), m_hdrFrameBuffer->getTextureDepthID());
    //stages.hdr.render();

    //// UI
    //stages.devHud.render();
    //stages.pda.render();
    //stages.pauseMenu.render();

    //// Cube face fade animation
    //if (m_increaseQuadAlpha) {
    //    static const f32 FADE_INC = 0.07f;
    //    m_coloredQuadAlpha += FADE_INC;
    //    if (m_coloredQuadAlpha >= 3.5f) {
    //        m_coloredQuadAlpha = 3.5f;
    //        m_increaseQuadAlpha = false;
    //    }
    //    m_coloredQuadRenderer.draw(m_quad, f32v4(0.0, 0.0, 0.0, glm::min(m_coloredQuadAlpha, 1.0f)));
    //} else if (m_coloredQuadAlpha > 0.0f) {
    //    static const float FADE_DEC = 0.01f;  
    //    m_coloredQuadRenderer.draw(m_quad, f32v4(0.0, 0.0, 0.0, glm::min(m_coloredQuadAlpha, 1.0f)));
    //    m_coloredQuadAlpha -= FADE_DEC;
    //}

    //if (m_shouldScreenshot) dumpScreenshot();

    //// Check for errors, just in case
    //checkGlError("GamePlayRenderPipeline::render()");
}

void GameplayRenderPipeline::destroy(bool shouldDisposeStages) {
    //
    //// Call base destroy
    //RenderPipeline::destroy(shouldDisposeStages);

    //m_hdrFrameBuffer->dispose();
    //delete m_hdrFrameBuffer;
    //m_hdrFrameBuffer = nullptr;

    //m_swapChain->dispose();
    //delete m_swapChain;
    //m_swapChain = nullptr;

    //m_quad.dispose();
}

void GameplayRenderPipeline::cycleDevHud(int offset /* = 1 */) {
    stages.devHud.cycleMode(offset);
}

void GameplayRenderPipeline::toggleNightVision() {
    if (!stages.nightVision.isActive()) {
        stages.nightVision.setActive(true);
        m_nvIndex = 0;
        stages.nightVision.setParams(m_nvParams[m_nvIndex]);
    } else {
        m_nvIndex++;
        if (m_nvIndex >= m_nvParams.size()) {
            stages.nightVision.setActive(false);
        } else {
            stages.nightVision.setParams(m_nvParams[m_nvIndex]);
        }
    }
}

void GameplayRenderPipeline::loadNightVision() {
    stages.nightVision.setActive(false);

    m_nvIndex = 0;
    m_nvParams.clear();

    vio::IOManager iom;
    const cString nvData = iom.readFileToString("Data/NightVision.yml");
    if (nvData) {
        Array<NightVisionRenderParams> arr;
        keg::ReadContext context;
        context.env = keg::getGlobalEnvironment();
        context.reader.init(nvData);
        keg::Node node = context.reader.getFirst();
        keg::Value v = keg::Value::array(0, keg::Value::custom(0, "NightVisionRenderParams", false));
        keg::evalData((ui8*)&arr, &v, node, context);
        for (size_t i = 0; i < arr.size(); i++) {
            m_nvParams.push_back(arr[i]);
        }
        context.reader.dispose();
        delete[] nvData;
    }
    if (m_nvParams.size() < 1) {
        m_nvParams.push_back(NightVisionRenderParams::createDefault());
    }
}

void GameplayRenderPipeline::toggleChunkGrid() {
    stages.chunkGrid.toggleActive();
}

void GameplayRenderPipeline::updateCameras() {
    const GameSystem* gs = m_soaState->gameSystem.get();
    const SpaceSystem* ss = m_soaState->spaceSystem.get();

    // Get the physics component
    auto& phycmp = gs->physics.getFromEntity(m_soaState->playerEntity);
    if (phycmp.voxelPositionComponent) {
        auto& vpcmp = gs->voxelPosition.get(phycmp.voxelPositionComponent);
        m_localCamera.setClippingPlane(0.1f, 10000.0f);
        m_localCamera.setPosition(vpcmp.gridPosition.pos);
        m_localCamera.setOrientation(vpcmp.orientation);
        m_localCamera.update();

        m_voxelsActive = true;
    } else {
        m_voxelsActive = false;
    }
    // Player is relative to a planet, so add position if needed
    auto& spcmp = gs->spacePosition.get(phycmp.spacePositionComponent);
    if (spcmp.parentGravityID) {
        auto& it = m_renderState->spaceBodyPositions.find(spcmp.parentEntityID);
        if (it != m_renderState->spaceBodyPositions.end()) {
            m_spaceCamera.setPosition(m_renderState->spaceCameraPos + it->second);
        } else {
            auto& gcmp = ss->m_sphericalGravityCT.get(spcmp.parentGravityID);
            auto& npcmp = ss->m_namePositionCT.get(gcmp.namePositionComponent);
            m_spaceCamera.setPosition(m_renderState->spaceCameraPos + npcmp.position);
        }
    } else {
        m_spaceCamera.setPosition(m_renderState->spaceCameraPos);
    }

    m_spaceCamera.setClippingPlane(0.1f, 100000000000.0f);
   
    m_spaceCamera.setOrientation(m_renderState->spaceCameraOrientation);
    m_spaceCamera.update();
}

void GameplayRenderPipeline::dumpScreenshot() {
    // Make screenshots directory
    vio::IOManager().makeDirectory("Screenshots");
    // Take screenshot
    dumpFramebufferImage("Screenshots/", m_viewport);
    m_shouldScreenshot = false;
}
