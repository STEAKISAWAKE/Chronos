add_executable(UpsilonLogTest main.c)

target_include_directories(UpsilonLogTest PUBLIC "${UPSILON_INCLUDE}/Utilities/")
target_link_libraries(UpsilonLogTest UpsilonUtilities)