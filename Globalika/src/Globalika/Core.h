#pragma once

#ifdef GLOB_PLATFORM_WINDOWS
	#ifdef GLOB_BUILD_DLL
		#define GLOBALIKA_API __declspec(dllexport)
	#else
		#define GLOBALIKA_API __declspec(dllimport)
	#endif
#else
	#error Globalika only support Windows!
#endif

#ifdef GLOB_DEBUG
	#define GLOB_ENABLE_ASSERTS
#endif

#ifdef GLOB_ENABLE_ASSERTS
	#define GLOB_ASSERT(x, ...) { if(!(x)) { GLOB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GLOB_CORE_ASSERT(x, ...) { if(!(x)) { GLOB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GLOB_ASSERT(x, ...)
	#define GLOB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GLOB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1) 
