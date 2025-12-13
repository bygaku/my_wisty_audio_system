message(STATUS "IS_WIN32_APP=${IS_WIN32_APP}")
file(GLOB SOURCE CONFIGURE_DEPENDS "*.h" "*.cpp")

if(IS_WIN32_APP)
    add_executable(${PROJECT_NAME} WIN32 ./winmain.cpp)

    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_APP)

    target_sources(${PROJECT_NAME}
            PRIVATE
            winmain.cpp
            ${SOURCE}
    )

else ()
    add_executable(${PROJECT_NAME} ./main.cpp)

    target_sources(${PROJECT_NAME}
            PRIVATE
            main.cpp
            ${SOURCE}
    )

endif()



target_include_directories(${PROJECT_NAME}
        PUBLIC
        ../include
)
