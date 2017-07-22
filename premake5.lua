workspace "timecycle24"
	configurations { "Release", "Debug" }
	location "build"
   
	files { "src/*.*" }
   
	includedirs { "src" }
	includedirs { os.getenv("RWSDK36") }
   
project "timecycle24"
	kind "SharedLib"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"
	targetextension ".asi"
	characterset ("MBCS")

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		debugdir "C:/Users/aap/games/gtasa"
		debugcommand "C:/Users/aap/games/gtasa/gta_sa.exe"
		postbuildcommands "copy /y \"$(TargetPath)\" \"C:\\Users\\aap\\games\\gtasa\\scripts\\timecycle24.asi\""


	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
		flags { "StaticRuntime" }
		debugdir "C:/Users/aap/games/gtasa"
		debugcommand "C:/Users/aap/games/gtasa/gta_sa.exe"
		postbuildcommands "copy /y \"$(TargetPath)\" \"C:\\Users\\aap\\games\\gtasa\\scripts\\timecycle24.asi\""
