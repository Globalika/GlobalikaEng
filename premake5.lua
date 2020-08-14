workspace "Globalika"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

project "Globalika"
	location "Globalika"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "globpch.h"
	pchsource "Globalika/src/globpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLOB_PLATFORM_WINDOWS",
			"GLOB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GLOB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GLOB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GLOB_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Globalika/vendor/spdlog/include",
		"Globalika/src"
	}

	links
	{
		"Globalika"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
	defines
	{
		"GLOB_PLATFORM_WINDOWS"
	}

	
	filter "configurations:Debug"
		defines "GLOB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GLOB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GLOB_DIST"
		optimize "On"