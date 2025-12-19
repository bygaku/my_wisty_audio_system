file(GLOB SOURCE CONFIGURE_DEPENDS "./src/*.cpp")
message(STATUS "./Common")

add_library(${MOD_COMMON}
        ${SOURCE}
)

target_include_directories(${MOD_COMMON}
        PUBLIC
        ./include
        ./include/utility
)