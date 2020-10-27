workspace "Globalika"
    architecture "x64"
    startproject "Sandbox"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 


-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Globalika/vendor/GLFW/include"
IncludeDir["Glad"] = "Globalika/vendor/Glad/include"
IncludeDir["ImGui"] = "Globalika/vendor/imgui"
IncludeDir["glm"] = "Hazel/vendor/glm"

group "Dependencies"
    include "Globalika/vendor/GLFW"
    include "Globalika/vendor/Glad"
    include "Globalika/vendor/imgui"

group ""

project "Globalika"
    location "Globalika"
    kind "SharedLib"
    language "C++"
    staticruntime "off"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "globpch.h"
    pchsource "Globalika/src/globpch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
    }
    
    links 
    { 
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        
        defines
        {
        	"GLOB_PLATFORM_WINDOWS",
        	"GLOB_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }
    
    filter "configurations:Debug"
        defines "GLOB_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "GLOB_RELEASE"
        runtime "Release"
        optimize "On"
    
    filter "configurations:Dist"
        defines "GLOB_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
     
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }
    
    includedirs
    {
        "Globalika/vendor/spdlog/include",
        "Globalika/src",
        "Globalika/vendor",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }
    
    links
    {
        "Globalika"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
    	
    defines
    {
        "GLOB_PLATFORM_WINDOWS"
    }
    
    
    filter "configurations:Debug"
        defines "GLOB_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "GLOB_RELEASE"
        runtime "Release"
        optimize "On"
    
    filter "configurations:Dist"
        defines "GLOB_DIST"
        runtime "Release"
        optimize "On"