################################################ Don't touch this section!
cmake_minimum_required(VERSION 4.0.2)
set(PROJECT_NAME "WAS")
set(PROJECT_VER "0.1.0")

# project settings.
project(${PROJECT_NAME}
        VERSION ${PROJECT_VER}
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
################################################

# Library name identification.
set(LIB_IMGUI "Imgui")
set(MOD_AUDIO "wwist_audio")
set(MOD_COMMON "wwist_utils")

# When adding a brand new libraries this project,
# You have to add "add_subdirectory(${LIB_DIR}/{library_directory_name}) in below"
# add_subdirectory(${LIB_DIR}/ ... )
set(LIB_DIR "./lib")
add_subdirectory(${LIB_DIR}/imgui)

# Add module directories.
add_subdirectory(./module)

# If this option is "OFF", The executable file will not be output.
option(BUILD_APP "*build application executable." ON)
# If you don't require the console screen during debug, "ON" this option.
option(IS_WIN32_APP "*build as WIN32 application." ON)
# If you wanna pop up window of console. "ON" this option.
option(POP_CONSOLE "*popup console-window" OFF)
# If testing modules, "ON" this option.
option(BUILD_TEST "*module test." OFF)

################################################

if(BUILD_TEST)
    add_subdirectory(./test)    # Test Mode
endif()
if(BUILD_APP)
    add_subdirectory(./app)     # Execution App
endif()
################################################