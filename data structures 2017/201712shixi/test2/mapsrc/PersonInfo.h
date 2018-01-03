using namespace std;
#include <string>

#ifndef PERSONINFO_H_INCLUDED
#define PERSONINFO_H_INCLUDED

class PersonInfo
{
private:
    string name;
    string sex;
    string degree;
    string job;
    string office;
    string telephone;
public:
    PersonInfo() {}
    PersonInfo(string _name):name(_name) {}
    friend istream& operator>>(istream& is, PersonInfo& thisInfo)
    {
        is >> thisInfo.name >> thisInfo.sex >>thisInfo.degree
            >>thisInfo.job  >>thisInfo.office >>thisInfo.telephone;
        return is;
    }
    friend ostream& operator<<(ostream& os, PersonInfo& thisInfo)
    {
        os << thisInfo.name <<" " <<thisInfo.sex <<" " <<thisInfo.degree
           <<" " <<thisInfo.job <<" " <<thisInfo.office <<" " <<thisInfo.telephone;
        return os;
    }
};


#endif // PERSONINFO_H_INCLUDED
