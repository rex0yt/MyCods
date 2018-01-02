#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

using namespace std;
#include <iostream>
#include "PersonNo.h"
#include "PersonInfo.h"

class Person
{
private:
    PersonNo no;
    PersonInfo info;
public:
    Person() {}
    Person(int _no):no(_no){}
    Person(PersonNo no,PersonInfo info):no(no),info(info) {}
    friend istream& operator>>(istream& is, Person& onePerson);
    friend ostream& operator<<(ostream& os, Person& onePerson);
    PersonNo getNo();

};


#endif // PERSON_H_INCLUDED
