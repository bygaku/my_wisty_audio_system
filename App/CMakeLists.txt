# Executable Application
if (IS_WIN32_APP) # When a debug console is not needed.
    add_executable(${PROJECT_NAME}
            WIN32
            src/main.cpp
    )

    target_compile_definitions(${PROJECT_NAME}
            PRIVATE
            WIN32_APP
    )
else () # Execution Application with Console-Window. * when you wanna use printf() etc function.
    add_executable(${PROJECT_NAME}
            src/main.cpp
    )
endif ()


if(POP_CONSOLE) # Enable Console-Window
    target_compile_definitions(${PROJECT_NAME}
            PRIVATE
            POPUP_CONSOLE
    )
endif()

# Linked libraries
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${LIB_IMGUI}
        d3d11
        dxgi
        #${MOD_AUDIO}
        ${MOD_COMMON}
)