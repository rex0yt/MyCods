#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

using namespace std;
#include <iostream>

class Person
{
private:
    int no;
    string name;
    string sex;
    string degree;
    string job;
    string office;
    string telephone;
public:
    Person() {}
    Person(int _no):no(_no){}
    int getNo() {return no;}
    string getName() {return name;}
    friend istream& operator>>(istream& is, Person& onePerson)
    {
        is >> onePerson.no >> onePerson.name >> onePerson.sex >>
                onePerson.degree >> onePerson.job >> onePerson.office
                >>onePerson.telephone;
        return is;
    }
    friend ostream& operator<<(ostream& os, Person& onePerson)
    {
        os <<onePerson.no <<" " <<onePerson.name <<" " <<onePerson.sex
          <<" " <<onePerson.degree <<" " <<onePerson.job <<" "
         <<onePerson.office <<" " <<onePerson.telephone <<endl;
        return os;
    }
};

#endif // PERSON_H_INCLUDED
