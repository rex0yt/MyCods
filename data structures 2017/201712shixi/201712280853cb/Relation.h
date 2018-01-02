#include "PersonNo.h"

#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

class Relation
{
    PersonNo per1;
    PersonNo per2;
    int weight;
public:
    Relation(){}
    Relation(PersonNo& p1, PersonNo& p2,int wei=0):per1(p1),per2(p2),weight(wei) {}
    PersonNo getPer1();
    PersonNo getPer2();
    friend istream& operator>>(istream& is, Relation& rela);//重载输入函数
    friend ostream& operator<<(ostream& os, Relation& rela);//重载输出函数

};

#endif // RELATION_H_INCLUDED
