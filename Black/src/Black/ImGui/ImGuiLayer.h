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

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
        
    private: 
        float m_Time = 0.0f;

    };
}
