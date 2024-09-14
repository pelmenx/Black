#pragma once
#include "Application.h"
#include "Log.h"

#ifdef BLACK_PLATFORM_WINDOWS

extern Black::Application* Black::CreateApplication();

int main(int argc, char** argv)
{
    Black::Log::Init();
    int a = 5;
    BLACK_CORE_WARN("Hello World!");
    BLACK_INFO("Hello World! Var={0}", a);
    
    auto app = Black::CreateApplication();
    app->run();
    delete app;
}

#endif