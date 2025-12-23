file(GLOB SOURCE CONFIGURE_DEPENDS "./src/*.cpp")

add_library(${MOD_COMMON}
        STATIC
        ${SOURCE}
)

target_include_directories(${MOD_COMMON}
        PUBLIC
        ./include
        ../../lib/imgui
)
