
# Create Library
add_library(UpsilonUtilities STATIC
    Log.cpp
)

target_include_directories(UpsilonUtilities PUBLIC "${UPSILON_INCLUDE}/Utilities")
