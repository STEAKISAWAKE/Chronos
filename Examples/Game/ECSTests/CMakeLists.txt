add_executable(ChronosECSTests main.cpp)

target_include_directories(ChronosECSTests PUBLIC "${CHRONOS_SOURCE}/Game")

target_link_libraries(ChronosECSTests ChronosGame)