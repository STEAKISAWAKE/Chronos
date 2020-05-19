add_executable(UpsilonECSTests main.cpp)

target_include_directories(UpsilonECSTests PUBLIC "${UPSILON_INCLUDE}/Game")

target_link_libraries(UpsilonECSTests UpsilonGame)