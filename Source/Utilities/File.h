#ifndef __CHRONOS_UTILITIES_FILE_H__
#define __CHRONOS_UTILITIES_FILE_H__

#include <sys/stat.h>
#include <string>

inline bool DoesFileExist(const std::string& path) {
    struct stat buffer;   
    return (stat (path.c_str(), &buffer) == 0); 
}

#endif // __CHRONOS_UTILITIES_FILE_H__