#pragma once

#include "Black/Core.h"
#include "Layer.h"

namespace Black
{
    class BLACK_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* layer);

        std::vector<Layer*>::iterator begin() {return m_LayerStack.begin(); }
        std::vector<Layer*>::iterator end() {return m_LayerStack.end(); }
    private:
        std::vector<Layer*> m_LayerStack;
        unsigned int m_LayerInsertIndex = 0;
    };
}

