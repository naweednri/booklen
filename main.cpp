#include <iostream>
#include "mem.h"
#include "log.h"
#include "db.h"
#include "json/json.h"

//#define debug 0

using std::endl;
using std::cout;
using std::cerr;

bool Logger::msLoggingEnabled=true;

#define log(...) MainLog.log(__func__,"(): ",__VA_ARGS__)

int main()
{
    //first we parse config.json file
    Logger MainLog;
    Json::Value root;
    std::ifstream ifs;
    ifs.open("config.json");
    if(ifs.fail())
    {
        cerr<<"can not open config.json"<<endl;
        log("error in opening config.json");
        return 1;
    }
    
    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;
    if (!parseFromStream(builder, ifs, &root, &errs)) 
    {
        cout << errs << endl;
        return EXIT_FAILURE;
    }
    
    
    // MainLog.log("test");


    return 0;
}