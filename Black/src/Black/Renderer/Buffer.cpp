#include "BlackPch.h"

#include "Buffer.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Black
{
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            {
                BLACK_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            }
        case (RendererAPI::OpenGl):
            {
                return new OpenGLVertexBuffer(vertices, size);
            }
        }
        BLACK_CORE_ASSERT(false, "RendererAPI::***Unknown*** is not supported!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            {
                BLACK_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            }
        case (RendererAPI::OpenGl):
            {
                return new OpenGLIndexBuffer(indices, count);
            }
        }
        BLACK_CORE_ASSERT(false, "RendererAPI::***Unknown*** is not supported!");
        return nullptr;
    }
}
