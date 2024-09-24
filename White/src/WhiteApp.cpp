#include "BlackPch.h"

#include <Black.h>

#include "ImGui/imgui.h"

class ExampleLayer : public Black::Layer
{
public:
    ExampleLayer()
        : Layer::Layer("ExampleLayer")
    {
    }

    void OnUpdate() override
    {
        // BLACK_INFO("ExapmleLayer::Update");
        if (Black::Input::IsKeyPressed(BLACK_KEY_TAB))
            BLACK_INFO("Tab key pressed");
    }

    void onEvent(Black::Event& e) override
    {
        // BLACK_TRACE("{0}", e);
    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Test");
        ImGui::End();
    }
};

class White : public Black::Application
{
public:
    White()
    {
        PushLayer(new ExampleLayer());
    }

    ~White()
    {
        
    }
};


Black::Application* Black::CreateApplication()
{
    return new White();
}