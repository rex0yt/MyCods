#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
using namespace std;

class Relation
{
private:
    int per1;
    int per2;
    int weight;
public:
    Relation(){}
    Relation(int p1,int p2,int wei=0):per1(p1),per2(p2),weight(wei) {}
    int getPer1() {return per1;}
    int getPer2() {return per2;}
    int getWeight() {return weight;}
    friend istream& operator>>(istream& is, Relation& rela)//重载输入函数
    {
        is >> rela.per1 >> rela.per2 >> rela.weight;
        return is;
    }
    friend ostream& operator<<(ostream& os, Relation& rela)//重载输出函数
    {
        os << rela.per1 << " " << rela.per2 << " " << rela.weight;
        return os;
    }
};

#endif // RELATION_H_INCLUDED
