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
    kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "BlackPch.h"
	pchsource "%{prj.name}/src/BlackPch.cpp"

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

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
		systemversion "latest"

		defines
		{
			"BLACK_PLATFORM_WINDOWS",
			"BLACK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "BLACK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLACK_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "BLACK_DIST"
		optimize "On"


project "White"
	location "White"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	
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
		"Black/src",
		"Black/vendor",
		"%{includeDir.glm}"
	}

	filter "system:windows"
		systemversion "latest"

	defines
	{
		"BLACK_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "BLACK_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "BLACK_RELEASE"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist"
		defines "BLACK_DIST"
		runtime "Release"
		optimize "On"
