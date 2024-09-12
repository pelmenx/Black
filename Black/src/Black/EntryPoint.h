#pragma once
#include "Application.h"

#ifdef BLACK_PLATFORM_WINDOWS

extern Black::Application* Black::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Black::CreateApplication();
    app->run();
    delete app;
}

#endif