#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Globalika {
	class GLOBALIKA_API Log
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
//Core log macros
#define GLOB_CORE_TRACE(...)    ::Globalika::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GLOB_CORE_INFO(...)     ::Globalika::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GLOB_CORE_WARN(...)     ::Globalika::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GLOB_CORE_ERROR(...)    ::Globalika::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GLOB_CORE_FATAL(...)    ::Globalika::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros

#define GLOB_TRACE(...)         ::Globalika::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GLOB_INFO(...)          ::Globalika::Log::GetClientLogger()->info(__VA_ARGS__)
#define GLOB_WARN(...)          ::Globalika::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GLOB_ERROR(...)         ::Globalika::Log::GetClientLogger()->error(__VA_ARGS__)
#define GLOB_FATAL(...)         ::Globalika::Log::GetClientLogger()->fatal(__VA_ARGS__)

