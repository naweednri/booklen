#include <mysqlx/xdevapi.h>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Db{
public:
    Db(string ip,string port);
private:
    //if connected to db, status var will be 1
    bool status;
    string ip,port;
};