add_library(ProtocolLabConf Config.cpp)
target_include_directories(ProtocolLabConf PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLabConf ProtocolLabCore)
