#pragma once
#include "ForgeRenderer.h"
#include <Tbx/Core/Rendering/IRenderer.h>
#include <Tbx/Core/Plugins/RegisterPlugin.h>
#include <Tbx/Runtime/Events/RenderEvents.h>
#include <Tbx/Runtime/Events/WindowEvents.h>
#include <Tbx/Runtime/Events/ApplicationEvents.h>
#include <Tbx/Runtime/App/GraphicsSettings.h>

namespace TheForgeRendering
{
    class ForgeRendererPlugin : public Tbx::Plugin, public ForgeRenderer
    {
    public:
        ForgeRendererPlugin() = default;
        ~ForgeRendererPlugin() final = default;

        void OnLoad() override;
        void OnUnload() override;

    private:
        void OnWindowFocusChanged(const Tbx::WindowFocusChangedEvent& e);
        void OnWindowResized(const Tbx::WindowResizedEvent& e);

        void OnGraphicsSettingsChanged(const Tbx::AppGraphicsSettingsChangedEvent& e);
        void OnRenderFrameRequest(Tbx::RenderFrameRequest& e);
        void OnClearScreenRequest(Tbx::ClearScreenRequest& e);
        void OnFlushRequest(Tbx::FlushRendererRequest& e);

        Tbx::GraphicsSettings _settings = {};
        Tbx::Color _clearColor = {};

        Tbx::UID _windowFocusChangedEventId = -1;
        Tbx::UID _windowResizedEventId = -1;

        Tbx::UID _graphicsSettingsChangedEventId = -1;

        Tbx::UID _setVSyncEventId = -1;
        Tbx::UID _renderFrameEventId = -1;
        Tbx::UID _clearScreenEventId = -1;
        Tbx::UID _flushEventId = -1;
    };
}

TBX_REGISTER_PLUGIN(TheForgeRendering::ForgeRendererPlugin);