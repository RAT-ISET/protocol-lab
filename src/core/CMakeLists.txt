add_library(ProtocolLabCore Calculator.cpp SignalData.cpp)
target_include_directories(ProtocolLabCore PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLabCore PRIVATE ProtocolLabBase)
