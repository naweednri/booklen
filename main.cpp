#include <iostream>
#include "mem.h"
#include "log.h"
#include "dbms.h"
#include "json/json.h"

//#define debug 0

using std::endl;
using std::cout;
using std::cerr;
using std::string;
bool Logger::msLoggingEnabled=true;

#define log(...) MainLog.log(__func__,"(): ",__VA_ARGS__)

int main()
{
    //first we parse config.json file
    Logger MainLog;                                 //for logging
    Json::Value root;                               //this variable contain root of config.json
    std::ifstream ifs;                              //for reading config.json 
    ifs.open("config.json");
    if(ifs.fail())
    {
        cerr<<"can not open config.json"<<endl;
        log("error in opening config.json");
        return 1;
    }
    //for being able to read comment
    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;
    if (!parseFromStream(builder, ifs, &root, &errs))
    //check if can parse config.json 
    {
        cerr << errs << endl;
        log("error in parsing config.json");
        return EXIT_FAILURE;
    }
    string ip,port,usr,passwd;
    // cout<<root["database"];
    ip=root["database"]["ip"].asString();
    port = root["database"]["port"].asString();
    usr = root["database"]["username"].asString();
    passwd =root["database"]["password"].asString();
    Dbms db(ip,port,usr,passwd);
    db.connect();
    db.getUsername(2);
    if(db.status)
    
    // MainLog.log("test");


    return 0;
}

