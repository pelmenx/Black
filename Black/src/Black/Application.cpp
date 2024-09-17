#include "BlackPch.h"

#include "Application.h"

// #include "Black/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

namespace Black
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    void Application::run()
    {
        while (m_Running)
        {
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }   
}
