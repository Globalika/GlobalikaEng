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

#define BIT(x) (1 << x)