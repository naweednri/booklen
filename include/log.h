#pragma once
#include <iostream>
#include <ctime>
#include <fstream>



class Logger
{
    public:
        static void enabledLogging(bool enable);
        static bool isLoggingEnabled();
        template<typename... Args>
        void log(const Args&... args0);
        void get();
    private:
        std::time_t vTime;
        char dateBuff[100];
        char msg[200];
        static const std::string dbLevel[4];
        template<typename T1>
        void logHleper(std::ofstream& ofs, const T1& t1);
        template<typename T1,typename... Tn>
        void logHelper(std::ofstream& ofs,const T1& t1,const Tn&... args);
        static const std::string msDebugFileName;
        static bool msLoggingEnabled;



};
template<typename... Args>
void Logger::log(const Args&... args)
{
    std::cout<<"msLoggingEnabled:"<<msLoggingEnabled<<std::endl;
    if(!msLoggingEnabled)
    {
        std::cerr<<"logging disabled"<<std::endl;
        return;
    }
    std::ofstream ofs(msDebugFileName,std::ios::app);
    if(ofs.fail())
    {
        std::cerr<<"Unable to open debug file...!"<<std::endl;
        return;
    }
    logHelper(ofs,args...);
    ofs<<std::endl;
}
template<typename T1>
void Logger::logHelper(std::ofstream& ofs,const T1& t1)
{
    ofs<<t1;
}
template<typename T1,typename... Tn>
void Logger::logHelper(std::ofstream& ofs,const T1& t1,const Tn&... args)
{
    ofs<<t1;
    logHelper(ofs,args...);
}