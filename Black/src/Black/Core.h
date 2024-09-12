#pragma once

#ifdef BLACK_PLATFORM_WINDOWS
    #ifdef BLACK_BUILD_DLL
        #define BLACK_API __declspec(dllexport)
    #else
        #define BLACK_API __declspec(dllimport)
    #endif
#endif