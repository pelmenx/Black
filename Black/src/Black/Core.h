#pragma once

#ifdef BLACK_DEBUG
    #define BLACK_ENABLE_ASSERTS
#endif

#ifdef BLACK_ENABLE_ASSERTS
    #define BLACK_ASSERT(x, ...) {if(!(x)) { BLACK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define BLACK_CORE_ASSERT(x, ...) {if(!(x)) { BLACK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define BLACK_ASSERT(x, ...)
    #define BLACK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))

#define BLACK_BIND_EVENT_FN(fn) std::bind(&ImGuiLayer::fn, this, std::placeholders::_1)
