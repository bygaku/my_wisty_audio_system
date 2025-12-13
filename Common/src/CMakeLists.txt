file(GLOB SOURCE CONFIGURE_DEPENDS "*.cpp")
message(STATUS "./Common/src")

target_sources(${PROJECT_NAME}
        PRIVATE
        ${SOURCE}
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ../include
)
