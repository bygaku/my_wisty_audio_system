# utils.
enable_testing()

include(FetchContent)
FetchContent_Declare(
        GoogleTest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(GoogleTest)

add_executable(${utils}
        utils_main.cpp
)

target_link_libraries(${utils}
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        ${MOD_COMMON}
)

add_test(NAME utility_test
        COMMAND
        $<TARGET_FILE:${utils}>
)

# Compiler options.
if(MSVC)
    target_compile_definitions(${utils}
            PRIVATE
            UNICODE     # Unicode mode
            _UNICODE    # Multi-byte mode
            NOMINMAX
    )

    set_property(TARGET ${utils}
            PROPERTY
            MSVC_CHARACTER_SET "Unicode"
    )   # use Unicode.
endif()