#pragma once

#ifdef BLACK_PLATFORM_WINDOWS
    #ifdef BLACK_BUILD_DLL
        #define BLACK_API __declspec(dllexport)
    #else
        #define BLACK_API __declspec(dllimport)
    #endif
#else
    #error Black only supports Windows!
#endif

#ifdef BLACK_ENABLE_ASSERTS
    #define BLACK_ASSERT(x, ...) {if(!(x)) { BLACK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define BLACK_CORE_ASSERT(x, ...) {if(!(x)) { BLACK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define BLACK_ASSERT(x, ...)
    #define BLACK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))
