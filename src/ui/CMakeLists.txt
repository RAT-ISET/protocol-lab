add_library(ProtocolLabUi UiCore.cpp)
target_include_directories(ProtocolLabUi PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLabUi ProtocolLabDeps OpenGL::GL)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/src)
