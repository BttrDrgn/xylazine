project_name = io.readfile("../project_name");
print("Project Name: " .. project_name);

loaded_bin = io.readfile("../loaded_bin");
print("Loaded Binary: " .. loaded_bin);

workspace(project_name)
	location "../build/"
	targetdir "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.platform}/"
	objdir "%{wks.location}/obj/%{prj.name}/%{cfg.buildcfg}-%{cfg.platform}/"
	buildlog "%{wks.location}/obj/%{cfg.platform}/%{cfg.buildcfg}-%{prj.name}.log"

	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	systemversion "latest"
	characterset "unicode"
	warnings "extra"

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
		defines "NDEBUG"
		optimize "full"
		runtime "release"
		symbols "off"

	filter "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	project(project_name)
		targetname(project_name)
		language "c++"
		kind "consoleapp"
		warnings "off"

		pchheader "stdafx.cpp"
		pchsource "../src/game/stdafx.cpp"
		forceincludes "stdafx.cpp"

		defines {
			"LOADED_BIN=\"".. loaded_bin .. "\"",
		}

		includedirs {
			"../src/loader/",
			"../src/game/",
		}

		files {
			"../src/loader/**",
			"../src/game/**",
		}

		linkoptions {
			"/NXCOMPAT:NO",
			"/IGNORE:4254",
			"/DYNAMICBASE:NO",
			"/SAFESEH:NO",
			"/LARGEADDRESSAWARE",
			"/LAST:.main",
		}