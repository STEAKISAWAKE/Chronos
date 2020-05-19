
# Create Library
add_library(UpsilonGame STATIC
    ComponentArray.cpp
)

# Include Library
target_include_directories(UpsilonGame PUBLIC "${UPSILON_INCLUDE}/Game")
target_include_directories(UpsilonGame PUBLIC "${UPSILON_INCLUDE}/Utilities")

# Include Others
target_link_libraries(UpsilonGame UpsilonUtilities)