#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Black
{
    class BLACK_API Log
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define BLACK_CORE_CRITICAL(...)    ::Black::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define BLACK_CORE_ERROR(...)       ::Black::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BLACK_CORE_WARN(...)        ::Black::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BLACK_CORE_INFO(...)        ::Black::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BLACK_CORE_TRACE(...)       ::Black::Log::GetCoreLogger()->trace(__VA_ARGS__)


// Client log macros
#define BLACK_CRITICAL(...)         ::Black::Log::GetClientLogger()->critical(__VA_ARGS__)
#define BLACK_ERROR(...)            ::Black::Log::GetClientLogger()->error(__VA_ARGS__)
#define BLACK_WARN(...)             ::Black::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BLACK_INFO(...)             ::Black::Log::GetClientLogger()->info(__VA_ARGS__)
#define BLACK_TRACE(...)            ::Black::Log::GetClientLogger()->trace(__VA_ARGS__)