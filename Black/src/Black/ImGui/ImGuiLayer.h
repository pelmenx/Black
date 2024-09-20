#pragma once

#include "Black/Layer.h"

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
        float m_Time = 0.0f;

    };
}
