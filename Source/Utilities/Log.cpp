#include "Log.h"

#include <iostream>
#include <assert.h>

void Log(const char* logContext, const char* logMessage)
{
    std::cout << logContext << ": " << logMessage << std::endl;
}

void LogError(const char* logContext, const char* errorMessage)
{
    std::cout << logContext << ": " << errorMessage << std::endl;
}

#if !defined(NDEBUG)
void assert_msg(bool expr, const char* msg)
{
    const bool e_ = expr;

    if(!e_)
    {
        fputs(msg, stderr);
        fputc('\n', stderr);
        assert(e_);
    }
}
#else // NDEBUG
void assert_msg(bool expr, const char* msg)
{
    if(!expr)
        LogError("BUG: ", msg);
}
#endif // NDEBUG