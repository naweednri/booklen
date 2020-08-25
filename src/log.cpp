#include "log.h"
#include <fstream>

void Logger::enableLogging(bool enable)
{
    msLoggingEnabled = enable;

}
bool Logger::isLoggingEnabled()
{
    return msLoggingEnabled;
}

void Logger::get()
{
    char buff[80];
    vTime = std::time(nullptr);
    std::strftime(buff, sizeof(buff), "[ %Y/%m/%d %H:%M:%S ]", std::localtime(&vTime));
    std::cout<<buff;
}
static const std::string dbgLevel[4]={"ERROR","INFO","WARNING","DEBUG"};
const std::string Logger::msDebugFileName = "debugfile.out";