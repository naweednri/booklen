#include "dbms.h"
#include <stdio.h>
// using std::string;
using std::cout;
using std::endl;
Dbms::Dbms(string ip,string port,string usr,string passwd) : ip(ip),port(port),usr(usr),passwd(passwd)
{
    

    try {
        con.Connect(_TSA("127.0.0.1,3306@booklend"), _TSA("root"), _TSA("1234"),SA_MySQL_Client);
        printf("We are connected!\n");

        /*
        The rest of the tutorial goes here!
        */

        
        printf("We are disconnected!\n");
    }
    catch(SAException &x) {
        con.Rollback();
        printf("%s\n", x.ErrText().GetMultiByteChars());
    }
       
        
            
    
}

void Dbms::connect()
{
    
}
std::string Dbms::getUsername(int id)
{
    
    SACommand select( &con, _TSA("SELECT fname, age FROM user "));
    select.Execute();
    select.FetchNext();
    SAString name = select[1].asString();
    
    printf("%s\n",select.Field(_TSA("fname")).asString().GetMultiByteChars());
    return test;
}

Dbms::~Dbms()
{
    std::cout<<"destructor"<<std::endl;
    con.Disconnect();
}