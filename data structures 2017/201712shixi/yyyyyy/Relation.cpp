#include "Relation.h"

PersonNo Relation::getPer1()
{
    return this->per1;
}

PersonNo Relation::getPer2()
{
    return this->per2;
}

istream& operator>>(istream& is, Relation& rela)//�������뺯��
{
    is >> rela.per1 >> rela.per2 >> rela.weight;
    return is;
}

ostream& operator<<(ostream& os, Relation &rela)//�����������
{
    os << rela.per1 << " " << rela.per2 << " " << rela.weight;
    return os;
}


