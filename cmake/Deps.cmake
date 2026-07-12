include(FetchContent)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.92.8
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(imgui)

add_library(ProtocolLabDeps INTERFACE)
target_link_libraries(ProtocolLabDeps INTERFACE imgui)
