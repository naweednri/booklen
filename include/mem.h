#include <iostream>

using std::string;
class Book;
class Member{
public:
    Member(int id=Member::newId);
    void getId();
private:
    string fname,lname;
    static int newId;
    int id;
    Book **book ;


};