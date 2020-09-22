// #include <mysqlx/xdevapi.h>
#include <SQLAPI.h>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
// using namespace ::mysqlx;
class Dbms{
public:
    Dbms(string ip,string port,string usr,string passwd);
    virtual ~Dbms();
    void connect();
    string getUsername(int);
    //if connected to db, status var will be 1
    bool status;
private:
    
    SAConnection con;
    string ip,port,usr,passwd,buff;
};