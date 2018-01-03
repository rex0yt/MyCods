using namespace std;
#include "Person.h"


istream& operator>>(istream& is, Person& onePerson)
{
    is >> onePerson.no;
    is >> onePerson.info;
    return is;
}

ostream& operator<<(ostream& os, Person& onePerson)
{
    os << onePerson.no << " ";
    os << onePerson.info << endl;
    return os;
}

PersonNo Person::getNo()
{
    return no;
}
