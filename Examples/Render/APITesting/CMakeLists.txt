add_executable( APITesting
    main.cpp
)

target_include_directories(APITesting PUBLIC "${CHRONOS_SOURCE}")
message("${ChronosRender}")
target_link_libraries(APITesting ChronosRender)