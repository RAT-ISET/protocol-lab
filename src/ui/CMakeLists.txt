add_library(ProtocolLabUi UiCore.cpp)
target_include_directories(ProtocolLabUi PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLabUi ProtocolLabDeps)
