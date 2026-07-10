add_executable(ProtocolLab Main.cpp)

target_include_directories(ProtocolLab PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLab PRIVATE ProtocolLabDeps)

include(GNUInstallDirs)

install(TARGETS ProtocolLab RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES ${CMAKE_SOURCE_DIR}/README.md DESTINATION share/doc/${PROJECT_NAME})
install(FILES ${CMAKE_SOURCE_DIR}/LICENSE DESTINATION share/licenses/${PROJECT_NAME})
