#include "BlackPch.h"

#include <Black.h>

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
    }

    void onEvent(Black::Event& e) override
    {
        BLACK_TRACE("{0}", e);
    }
};

class White : public Black::Application
{
public:
    White()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Black::ImGuiLayer());
    }

    ~White()
    {
        
    }
};


Black::Application* Black::CreateApplication()
{
    return new White();
}