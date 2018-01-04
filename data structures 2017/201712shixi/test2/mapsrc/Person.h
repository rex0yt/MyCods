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
    string getSex() {return sex;}
    string getDegree() {return degree;}
    string getJob() {return job;}
    string getOffice() {return office;}
    string getTelephone() {return telephone;}
    void setNo(int _no) {this->no=_no;}
    void setName(string name) {this->name=name;}
    void setSex(string sex) {this->sex=sex;}
    void setDegree(string degree) {this->degree=degree;}
    void setJob(string job) {this->job=job;}
    void setOffice(string office) {this->office=office;}
    void setTelephone(string tele) {this->telephone=tele;}
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
