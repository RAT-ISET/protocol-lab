add_library(ProtocolLabUi UiCore.cpp Render.cpp Node.cpp)
target_include_directories(ProtocolLabUi PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLabUi ProtocolLabDeps ProtocolLabCore OpenGL::GL)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/src)
