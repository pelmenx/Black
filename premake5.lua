workspace "Black"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcgf}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
includeDir = {}
includeDir["GLFW"] = "Black/vendor/GLFW/include"

include "Black/vendor/GLFW"

project "Black"
    location "Black"
    kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "BlackPch.h"
	pchsource "%{prj.name}/src/BlackPch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}
    
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{includeDir.GLFW}"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BLACK_PLATFORM_WINDOWS",
			"BLACK_BUILD_DLL",
			"BLACK_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/White")
		}

	filter "configurations:Debug"
		defines "BLACK_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "BLACK_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "BLACK_DIST"
		symbols "On"


project "White"
	location "White"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	links
	{
		"Black"
	}

	includedirs
	{
		"Black/vendor/spdlog/include",
		"Black/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"BLACK_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "BLACK_DEBUG"
		symbols "On"
	
	filter "configurations:Debug"
		defines "BLACK_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "BLACK_DIST"
		symbols "On"