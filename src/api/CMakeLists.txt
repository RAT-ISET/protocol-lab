add_library(ProtocolLabApi Actions.cpp)
target_include_directories(ProtocolLabApi PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLabApi ProtocolLabDeps)
