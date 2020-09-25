#include "dbms.h"
#include <stdio.h>

// using std::string;
using std::cout;
using std::endl;
using std::string;
class Member;
Dbms::Dbms(string dbName,string ip,string port,string usr,string passwd) : dbName(dbName),ip(ip),port(port),usr(usr),passwd(passwd),status(0)
{
    string temp = ip + ","+port+"@"+dbName;
    try {
        con.Connect(_TSA(temp.c_str()),_TSA(usr.c_str()),_TSA(passwd.c_str()),SA_MySQL_Client);
        printf("We are connected!\n");
        status = 1;

        
    }
    catch(SAException &x) {
        con.Rollback();
        printf("%s\n", x.ErrText().GetMultiByteChars());
        status =0;
    }
       
        
            
    
}

void Dbms::connect()
{
    
}
// class Member;
Member* Dbms::getUser(int id,Member* memb)
{
    

    
    SACommand select( &con, _TSA("SELECT * FROM user "));
    select.Execute();
    select.FetchNext();
    SAString name = select[2].asString();
    memb->fname =select.Field(_TSA("fname")).asString().GetMultiByteChars();
    memb->lname = select.Field(_TSA("lname")).asString().GetMultiByteChars();
    memb->phone = select.Field(_TSA("phone")).asString().GetMultiByteChars();
    // memb->rank = select.Field(_TSA("rank")).asString().GetMultiByteChars();
    
    return memb;
}

Dbms::~Dbms()
{
    std::cout<<"disconnected...!"<<std::endl;
    con.Disconnect();
}