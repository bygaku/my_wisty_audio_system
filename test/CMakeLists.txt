# test case.
set(utils "utils_test")
set(audio "audio_test")

add_subdirectory(./utils)
add_subdirectory(./audio)

# Compiler options.
if(MSVC)
    add_compile_options(
            /utf-8      # using UTF-8
            /W4         # warning level: 4
            /wd4819     # suppression of character encoding warnings
            /TP         # all src file written by cxx.
    )
endif()