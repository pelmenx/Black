#include "BlackPch.h"
#include "LayerStack.h"

namespace Black
{
    LayerStack::LayerStack()
    {
        m_LayerIterator = m_LayerStack.begin();
    }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_LayerStack)
            delete layer;
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_LayerIterator = m_LayerStack.emplace(m_LayerIterator, layer);
    }

    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_LayerStack.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto it = std::find(m_LayerIterator, m_LayerStack.end(), layer);
        if (it != m_LayerStack.end())
        {
            m_LayerStack.erase(it);
            m_LayerIterator--;
        }
    }

    void LayerStack::PopOverlay(Layer* layer)
    {
        auto it = std::find(m_LayerIterator, m_LayerStack.end(), layer);
        if (it != m_LayerStack.end())
            m_LayerStack.erase(it);
    }
}
