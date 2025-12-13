file(GLOB SOURCE CONFIGURE_DEPENDS "*.cpp")
message(STATUS "./Common/src")
message(STATUS "IS_WIN32_APP=${IS_WIN32_APP}")

target_sources(${PROJECT_NAME}
        PRIVATE
        ${SOURCE}
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ../include
)
