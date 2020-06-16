#include <filesystem>

std::string getExePath()
{
    return std::string(std::filesystem::current_path()) + "/";
}