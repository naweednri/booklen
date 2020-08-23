
#include <iostream>
#include "mem.h"

using std::string;
using std::cout;
using std::endl;

Member::Member(int id)
{
    this->id = id;
    newId++;
}
void Member::getId()
{
    cout<<id<<endl;
}

int Member::newId = 1;