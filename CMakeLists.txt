cmake_minimum_required(VERSION 4.0.2)
set(PROJECT_NAME "AudioSystem")
set(PROJECT_VER "0.1.0")

################################################ Don't touch this section!
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

# When adding a brand new libraries this project,
# You have to add "add_subdirectory(${LIB_DIR}/{library_directory_name}) in below"
set(LIB_DIR "./lib")
add_subdirectory(${LIB_DIR}/imgui)
# add_subdirectory(${LIB_DIR}/ ... )

# If you have to Console-Message in this project for Debug,
# IS_WIN32_APP set OFF.
set(IS_WIN32_APP OFF)
set(IS_TEST_MODE ON)
# Set the directory containing winmain.cpp and main.cpp.
set(COMMON "Common/src")

################################################ Don't touch this section!
# Test Code
if(IS_TEST_MODE)
    add_subdirectory(./Test)
else()
if(IS_WIN32_APP) # When a debug console is not needed.
    add_executable(${PROJECT_NAME}
            WIN32
            ${COMMON}/winmain.cpp
    )

    target_compile_definitions(${PROJECT_NAME}
            PRIVATE
            WIN32_APP
    )

    target_sources(${PROJECT_NAME}
            PRIVATE
            ${COMMON}/winmain.cpp
    )
else () # For debug console display
    add_executable(${PROJECT_NAME}
            ${COMMON}/main.cpp
    )

    target_sources(${PROJECT_NAME}
            PRIVATE
            ${COMMON}/main.cpp
    )
endif()

# compiler opt.
if(MSVC)
    target_compile_definitions(${PROJECT_NAME}
            PRIVATE
            UNICODE
            _UNICODE
    )

    set_target_properties(${PROJECT_NAME}
            PROPERTIES
            CHARACTER_SET Unicode
    )

    target_compile_options(${PROJECT_NAME}
            PRIVATE
            /TP
    )
endif()
################################################

# Linked libraries
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        imgui
        d3d11
        dxgi
)

# User sub directory
add_subdirectory(./Audio)
add_subdirectory(./Common)

endif()