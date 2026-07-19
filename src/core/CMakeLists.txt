add_library(ProtocolLabCore Calculator.cpp SignalData.cpp Session.cpp Workspace.cpp Environment.cpp)
target_include_directories(ProtocolLabCore PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ProtocolLabCore PRIVATE ProtocolLabBase ProtocolLabDeps ProtocolLabUi)
