#ifndef PERSONNO_H_INCLUDED
#define PERSONNO_H_INCLUDED

using namespace std;
#include <iostream>

class PersonNo
{
    int no;
public:
    PersonNo(){}
    PersonNo(int _no)
    {
        this->no = _no;
    }
    void setNo(int no)
    {
        this->no = no;
    }
    int getNo() const
    {
        return this->no;
    }
    friend bool operator==(const PersonNo& right, const PersonNo& left)
    {
        return right.getNo() == left.getNo();
    }
    friend istream& operator>>(istream& is, PersonNo& thisNo)
    {
        is >> thisNo.no;
        return is;
    }
    friend ostream& operator<<(ostream& os, PersonNo& thisNo)
    {
        os << thisNo.no;
        return os;
    }
};


#endif // PERSONNO_H_INCLUDED
