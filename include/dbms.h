// #include <mysqlx/xdevapi.h>
#ifndef DBMS_H
#define DBMS_H

#include <SQLAPI.h>
#include <iostream>
#include <vector>


#include "mem.h"


using std::string;
using std::cout;
using std::endl;
// using namespace ::mysqlx;
class Member;
class Dbms{
public:
    Dbms(string dbName,string ip,string port,string usr,string passwd);
    virtual ~Dbms();
    friend class Member;
    
    void connect();
    Member* getUser(int,Member*);
    //if connected to db, status will be 1
    bool status;
private:
    // Member* tempUser;

    static SAConnection con;
    string ip,port,usr,passwd,buff,dbName;
};
#endif