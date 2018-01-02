using namespace std;
#include <string>

#ifndef PERSONINFO_H_INCLUDED
#define PERSONINFO_H_INCLUDED

class PersonInfo
{
private:
    string name;
public:
    PersonInfo() {}
    PersonInfo(string _name):name(_name) {}
    friend istream& operator>>(istream& is, PersonInfo& thisInfo)
    {
        is >> thisInfo.name;
        return is;
    }
    friend ostream& operator<<(ostream& os, PersonInfo& thisInfo)
    {
        os << thisInfo.name;
        return os;
    }
};


#endif // PERSONINFO_H_INCLUDED
