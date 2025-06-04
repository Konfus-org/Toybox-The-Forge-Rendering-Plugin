#include "ForgeRenderer.h"

namespace TheForgeRendering
{
    ForgeRenderer::ForgeRenderer()
    {
    }

    void ForgeRenderer::ProcessData(const Tbx::RenderData& data)
    {
        const auto& command = data.GetCommand();
        const auto& payload = data.GetPayload();
        switch (command)
        {
            case Tbx::RenderCommand::None:
            {
                TBX_VERBOSE("OpenGl Renderer: Processing none cmd...");
                break;
            }
            case Tbx::RenderCommand::Clear:
            {
                TBX_VERBOSE("OpenGl Renderer: Processing clear cmd...");

                const auto& color = std::any_cast<const Tbx::Color&>(payload);
                Clear(color);
                break;
            }
            case Tbx::RenderCommand::CompileMaterial:
            {
                TBX_VERBOSE("OpenGl Renderer: Processing compile material cmd...");

                const auto& material = std::any_cast<const Tbx::Material&>(payload);
                CompileShader(material.GetShader());
                break;
            }
            case Tbx::RenderCommand::UploadMaterialsTextures:
            {
                TBX_VERBOSE("OpenGl Renderer: Processing upload material textures cmd...");

                const auto& material = std::any_cast<const Tbx::Material&>(payload);

                int textureSlot = 0;
                for (const auto& texture : material.GetTextures())
                {
                    UploadTexture(texture, textureSlot);
                    textureSlot++;
                }
                break;
            }
            case Tbx::RenderCommand::UploadMaterialShaderData:
            {
                TBX_VERBOSE("OpenGl Renderer: Processing upload material data cmd...");

                const auto& shaderData = std::any_cast<const Tbx::ShaderData&>(payload);
                UploadShaderData(shaderData);
                break;
            }
            case Tbx::RenderCommand::SetMaterial:
            {
                TBX_VERBOSE("OpenGl Renderer: Processing set material cmd...");

                const auto& material = std::any_cast<const Tbx::Material&>(payload);
                SetMaterial(material);
                break;
            }
            case Tbx::RenderCommand::RenderMesh:
            {
                TBX_VERBOSE("OpenGl Renderer: Processing mesh cmd...");

                const auto& mesh = std::any_cast<const Tbx::Mesh&>(payload);
                Draw(mesh);
                break;
            }
            default:
            {
                TBX_ASSERT(false, "Unknown render command type.");
                break;
            }
        }
    }

    void ForgeRenderer::SetContext(const std::weak_ptr<Tbx::IRenderSurface>& context)
    {
        _renderSurface = context.lock()->GetNativeHandle();
    }

    void ForgeRenderer::SetViewport(const Tbx::Size& size)
    {
        _viewportSize = size;
    }

    void ForgeRenderer::SetResolution(const Tbx::Size& size)
    {
        _resolution = size;
    }

    void ForgeRenderer::SetVSyncEnabled(bool enabled)
    {
        _vsyncEnabled = enabled;
    }

    void ForgeRenderer::UploadTexture(const Tbx::Texture& texture, Tbx::uint slot)
    {
    }

    void ForgeRenderer::CompileShader(const Tbx::Shader& shader)
    {
    }

    void ForgeRenderer::UploadShaderData(const Tbx::ShaderData& data)
    {
    }

    void ForgeRenderer::SetApi(Tbx::GraphicsApi api)
    {
        auto settings = RendererDesc();

        switch (api)
        {
            case Tbx::GraphicsApi::Vulkan:
            {
                break;
            }
            case Tbx::GraphicsApi::Metal:
            {
#ifndef TBX_PLATFORM_OSX
                TBX_ASSERT(false, "Cannot use metal on a non-Apple platform!");
#endif
                break;
            }
            case Tbx::GraphicsApi::DirectX:
            {
#ifndef TBX_PLATFORM_WINDOWS
                TBX_ASSERT(false, "Cannot use directX on a non-Windows platform!")
#endif
                break;
            }
            default:
            {
                TBX_ASSERT(false, "Unknown graphics API!");
                break;
            }
        }

        initGPUConfiguration(settings.pExtendedSettings);
        initRenderer("Toybox", &settings, &_forgeRenderer);
    }

    void ForgeRenderer::Flush()
    {
    }

    void ForgeRenderer::Clear(const Tbx::Color& color)
    {
    }

    void ForgeRenderer::BeginDraw()
    {
    }

    void ForgeRenderer::EndDraw()
    {
    }

    void ForgeRenderer::SetMaterial(const Tbx::Material& material)
    {
    }

    void ForgeRenderer::Draw(const Tbx::Mesh& mesh)
    {
    }

    void ForgeRenderer::Redraw()
    {
    }
}
