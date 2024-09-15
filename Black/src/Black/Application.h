#pragma once
#include "Core.h"

namespace Black
{
    class BLACK_API Application
    {
    public:
        Application() {}
        virtual ~Application() {}

        void run();
    };
    // To be defined in CLIENT
    Application* CreateApplication();

}

