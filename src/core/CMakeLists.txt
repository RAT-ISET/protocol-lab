add_library(ProtocolLabCore BaseWave.cpp Calculator.cpp)
target_include_directories(ProtocolLabCore PRIVATE ${CMAKE_SOURCE_DIR}/include)
