#pragma once

#include "Black/Core.h"
#include "Black/Events/Event.h"

namespace Black
{
    class Layer
    {
    public:
        Layer(const std::string & name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
        virtual void onEvent(Event & e) {}

        inline const std::string & getName() const { return m_DebugName; }
    protected:
        std::string m_DebugName;
    };
}

