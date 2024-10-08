#pragma once

#include "Window.h"
#include "Black/LayerStack.h"
#include "Events/ApplicationEvent.h"

#include "Black/ImGui/ImGuiLayer.h"

#include "Black/Renderer/Shader.h"

class Shader;

namespace Black
{
    class Application
    {
    public:
        Application();
        virtual ~Application() {}

        void run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        inline static Application& Get() {return *s_Instance; } 
        inline Window& GetWindow() { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application* s_Instance;

        unsigned int m_VertexArray;
        unsigned int m_VertexBuffer;
        unsigned int m_IndexBuffer;
        std::unique_ptr<Shader> m_Shader;
         
    };
    // To be defined in CLIENT
    Application* CreateApplication();

}

