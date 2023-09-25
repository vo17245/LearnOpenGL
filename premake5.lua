workspace "LearnOpenGL"
    configurations {"Debug","Release"}
    location "build"
    architecture ("x86_64")
project "LearnOpenGL"
    kind "ConsoleApp"
    staticruntime "on"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"
    files {"src/**.cpp","src/**.h"}

    includedirs
    {
        "src"
    }
    defines{"GLEW_STATIC"}
    libdirs 
    {
        "dependencies/glew-2.1.0/lib/Release/x64",
        "dependencies/glfw-3.3.8.bin.WIN64/lib-vc2022",
        "dependencies/glew-2.1.0/bin/Release/x64",
    }
    includedirs 
    {
        "dependencies/glew-2.1.0/include",
        "dependencies/glfw-3.3.8.bin.WIN64/include",
        "vendor",
    }
    links { "glfw3_mt","glew32s","OpenGL32" }
   
    filter "configurations:Debug"
        defines {"DEBUG"}

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"


        
    
    
    

        
    