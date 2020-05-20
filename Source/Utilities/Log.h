#ifndef __CHRONOS_UTILITIES_LOG_H__
#define __CHRONOS_UTILITIES_LOG_H__

#include <stdbool.h>

void Log(const char* logContext, const char* logMessage); /* Log a message to the console */
void LogError(const char* logContext, const char* errorMessage); /* Log an error to the console */

void assert_msg(bool expr, const char* msg);

#endif /* __CHRONOS_UTILITIES_LOG_H__ */