#pragma once

#include "Black/Layer.h"

#include "Black/Events/KeyEvent.h"
#include "Black/Events/MouseEvent.h"
#include "Black/Events/ApplicationEvent.h"

namespace Black
{
    class BLACK_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void onEvent(Event & e) override;
    
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent & e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent & e);
        bool OnMouseMovedEvent(MouseMovedEvent & e);
        bool OnMouseScrollEvent(MouseScrolledEvent & e);
        
        bool OnKeyPressedEvent(KeyPressedEvent & e);
        bool OnKeyReleasedEvent(KeyReleasedEvent & e);
        bool OnKeyTypedEvent(KeyTypedEvent & e);
        
        bool OnWindowResize(WindowResizeEvent & e);
        
    private: 
        float m_Time = 0.0f;

    };
}
