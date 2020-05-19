#include "Log.h"

int main()
{
    Log("Log Context", "Log Message!");
    Log("Context is to help message understanding", "Context could be used to show which function failed.");
    LogError("DynamicArray::PushBack", "Could not push back!");
    LogError("Not Real", "All of these errors are fake except for assertation problems!");

    LogError("Context", "Could not error!");
}
