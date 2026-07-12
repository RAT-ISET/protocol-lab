add_executable(ProtocolLab Main.cpp)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    if (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
        set_target_properties(ProtocolLab PROPERTIES WIN32_EXECUTABLE TRUE)
    endif ()
endif ()

target_include_directories(ProtocolLab PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLab PRIVATE ProtocolLabDeps ProtocolLabUi)

include(GNUInstallDirs)

install(TARGETS ProtocolLab RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES ${CMAKE_SOURCE_DIR}/README.md DESTINATION share/doc/${PROJECT_NAME})
install(FILES ${CMAKE_SOURCE_DIR}/LICENSE DESTINATION share/licenses/${PROJECT_NAME})

add_subdirectory(core)
add_subdirectory(ui)
