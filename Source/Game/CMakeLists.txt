
# Create Library
add_library(ChronosGame STATIC
    ComponentArray.cpp
)

# Include Library
target_include_directories(ChronosGame PUBLIC "${CHRONOS_INCLUDE}/Game")
target_include_directories(ChronosGame PUBLIC "${CHRONOS_INCLUDE}/Utilities")

# Include Others
target_link_libraries(ChronosGame ChronosUtilities)