require "progcalc"

project_name = io.readfile("./project_name");
print("Project Name: " .. project_name);

loaded_bin = io.readfile("./loaded_bin");
print("Loaded Binary: " .. loaded_bin);

workspace(project_name)
	location "./build/"
	targetdir "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.platform}/"
	objdir "%{wks.location}/obj/%{prj.name}/%{cfg.buildcfg}-%{cfg.platform}/"
	buildlog "%{wks.location}/obj/%{cfg.platform}/%{cfg.buildcfg}-%{prj.name}.log"

	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	systemversion "latest"
	characterset "ascii"
	warnings "extra"
	exceptionhandling "off"

	flags {
		"noincrementallink",
		"no64bitchecks",
		"shadowedvariables",
		"undefinedidentifiers",
		"multiprocessorcompile",
	}

	platforms {
		"x86",
	}

	configurations {
		"Release",
		"Debug",
	}

	--x86
	filter "platforms:x86"	
		architecture "x86"
	--end

	filter "Release"
		defines "DEBUG"
		optimize "debug"
		runtime "release"
		symbols "on"

	filter "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "release"
		symbols "on"

	project(project_name)
		targetname(project_name)
		language "c++"
		kind "consoleapp"
		warnings "off"

		pchheader "stdafx.hpp"
		pchsource "./src/game/stdafx.cpp"
		forceincludes "stdafx.hpp"

		defines {
			"LOADED_BIN=\"".. loaded_bin .. "\"",
			"PROJECT_NAME=\"".. project_name .. "\""
		}

		syslibdirs {
			"$(DXSDK_DIR)Lib/x86",
		}

		links {
			"d3d9",
			"dxguid",
			"dinput8",
		}

		includedirs {
			"./src/loader/",
			"./src/game/",
			"./src/memory/",
			"./src/",
			"$(DXSDK_DIR)Include",
		}

		files {
			"./src/loader/**",
			"./src/game/**",
			"./src/memory/**",
		}

		linkoptions {
			"/NXCOMPAT:NO",
			"/IGNORE:4254",
			"/DYNAMICBASE:NO",
			"/SAFESEH:NO",
			"/LARGEADDRESSAWARE",
			"/LAST:.main",
		}