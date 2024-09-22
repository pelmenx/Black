workspace "Black"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "White"

outputdir = "%{cfg.buildcgf}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
includeDir = {}
includeDir["GLFW"] = "Black/vendor/GLFW/include"
includeDir["Glad"] = "Black/vendor/Glad/include"
includeDir["ImGui"] = "Black/vendor/ImGui"
includeDir["glm"] = "Black/vendor/glm"

group "Dependencies"
	include "Black/vendor/GLFW"
	include "Black/vendor/Glad"
	include "Black/vendor/ImGui"
group ""

project "Black"
    location "Black"
    kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	staticruntime "Off"

	pchheader "BlackPch.h"
	pchsource "%{prj.name}/src/BlackPch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
    
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{includeDir.GLFW}",
		"%{includeDir.Glad}",
		"%{includeDir.ImGui}",
		"%{includeDir.glm}"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"BLACK_PLATFORM_WINDOWS",
			"BLACK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/White/\"")
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
	staticruntime "Off"
	
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
		"Black/src",
		"%{includeDir.glm}"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

	defines
	{
		"BLACK_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "BLACK_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Debug"
		defines "BLACK_RELEASE"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist"
		defines "BLACK_DIST"
		runtime "Release"
		symbols "On"
