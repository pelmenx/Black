#pragma once

#include "Core.h"

#include "Window.h"
#include "Black/LayerStack.h"
#include "Events/ApplicationEvent.h"

namespace Black
{
    class BLACK_API Application
    {
    public:
        Application();
        virtual ~Application() {}

        void run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
         
    };
    // To be defined in CLIENT
    Application* CreateApplication();

}

