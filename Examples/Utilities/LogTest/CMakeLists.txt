add_executable(ChronosLogTest main.c)

target_include_directories(ChronosLogTest PUBLIC "${CHRONOS_INCLUDE}/Utilities/")
target_link_libraries(ChronosLogTest ChronosUtilities)