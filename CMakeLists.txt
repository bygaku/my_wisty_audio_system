cmake_minimum_required(VERSION 4.0)
set(PROJECT_NAME "AudioSystem")
set(PROJECT_VER "0.1.0")

project(${PROJECT_NAME} VERSION ${PROJECT_VER} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(IS_WIN32_APP OFF)

# compiler opt
if(MSVC)
    add_compile_options(/utf-8 /TP)
endif()

set(COMMON "Common/src")
if(IS_WIN32_APP)
    add_executable(${PROJECT_NAME} WIN32 ${COMMON}/winmain.cpp)

    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_APP)

    target_sources(${PROJECT_NAME}
            PRIVATE
            ${COMMON}/winmain.cpp
    )
else ()
    add_executable(${PROJECT_NAME} ${COMMON}/main.cpp)

    target_sources(${PROJECT_NAME}
            PRIVATE
            ${COMMON}/main.cpp
    )
endif()

add_subdirectory(./Audio)
add_subdirectory(./Common)
