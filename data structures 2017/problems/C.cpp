#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

template <typename Type>
class ListNode
{
public:
    Type data;
    ListNode<Type> *next;
public:
    ListNode(){ }
    ListNode(Type _data, ListNode<Type> *_next=NULL)
        :data(_data),next(_next)
    {

    }
    ListNode& operator=(const ListNode<Type>& left)
    {
        this->data = left.data;
        this->next = left.next;
        return *this;
    }
    bool Calc()
    {
        data.Calc();
        return true;
    }
    bool operator<(const ListNode& left)
    {
        return this->data < left.data;
    }
};

template <typename Type>
class LinkedList
{
private:
    ListNode<Type> *first, *last;
    int size;
public:
    LinkedList():first(NULL),last(NULL),size(0) {}

    bool Insert(const ListNode<Type>& left)
    {
        ListNode<Type> *pnt = new ListNode<Type>;
        *pnt = left;
        if(first == NULL)
        {
            first = last = pnt;
            first->next = NULL;
            size = 1;
        }
        else
        {
            pnt->next = last->next;
            last->next = pnt;
            last = pnt;
            size ++;
        }
        return true;
    }
    bool Insert(const ListNode<Type>&left, int index)
    {
        if(index<=0 || index>size+1)
        {
            return false;
        }

        ListNode<Type> *pnt = new ListNode<Type>;
        *pnt = left;

        if(index == 1)
        {
            pnt->next = first;
            first = pnt;
            size ++;
            return true;
        }
        if(index == size+1)
        {
            pnt->next = last->next;
//            pnt->next = NULL;
            last->next = pnt;
            last = pnt;
            size ++;
            return true;
        }
        else
        {
            ListNode<Type> *tmpPnt = first, *pre;
            while(--index)
            {
                pre = tmpPnt;
                tmpPnt = tmpPnt->next;
            }
            pnt->next = tmpPnt;
            pre->next = pnt;
            size ++;
        }
        return true;
    }
    friend ostream& operator<<(ostream &os, const LinkedList<Type> &left)
    {
        ListNode<Type> *pnt = left.first;
        if(left.first == NULL)
        {

        }
        else
        {
            while(pnt)
            {
                os << pnt->data;
                pnt = pnt->next;
            }
        }
        return os;
    }
    int Search(const ListNode<Type>& left)const//return index [1, size]
    {
        ListNode<Type> *tmpPnt = first;
        int cnt = 1;
        while(tmpPnt)
        {
            if(tmpPnt->data == left.data)
            {
                return cnt;
            }
            tmpPnt = tmpPnt->next;
            cnt ++;
        }
        return 0;
    }
    ListNode<Type>* operator[](int index)
    {
        if(index<=0 || index>size)
        {
            return NULL;
        }
        ListNode<Type> *tmpPnt = first;
        while(-- index)
        {
            tmpPnt = tmpPnt->next;
        }
        return tmpPnt;
    }
    int LowBound(const ListNode<Type> &left)const
    {
        ListNode<Type> *pnt = first;
        int index = 1;
        while(pnt)
        {
            if(left.data <= pnt->data)
                return index;
            pnt = pnt->next;
            index ++;
        }
        return 0;
    }
    bool CalcAvg()
    {
        ListNode<Type> *pnt = first;
        while(pnt)
        {
            pnt->Calc();
            pnt = pnt->next;
        }
        return true;
    }
    bool Sort()
    {
        ListNode<Type> *tmp;
        for(int i=1; i<=size; i++)
        {
            tmp = this->operator[](i);
            for(int j=i+1; j<=size; j++)
            {
                if(tmp->data < (this->operator[](j))->data)
                {
                    tmp = this->operator[](j);
                }
            }
            swap(tmp->data, (this->operator[](i))->data);
            tmp = this->operator[](i);
            tmp->data.Rank = i;
        }
        return true;
    }
};
class Data
{
public:
    int No;
    string Name;
    double g1,g2,g3,avg;
    int Rank;
public:
    friend istream& operator>>(istream& is, Data& left)
    {
        is >> left.No >> left.Name >> left.g1 >> left.g2 >> left.g3;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Data &left)
    {
        os << fixed << setprecision(2)
            << left.No << " " << left.Name << " "
            << left.g1 << " " << left.g2 << " "
            << left.g3 << " " << left.avg << " "
            << left.Rank << endl;
        return os;
    }
    bool Calc()
    {
        double cnt = 0;
        cnt = g1 + g2 + g3;
        avg = cnt / 3.0;
        return true;
    }
    bool operator< (const Data& left)const
    {
        return avg < left.avg;
    }
};

int main()
{
//    freopen("data.txt","r",stdin);

    int n;
    LinkedList<Data> mylist;
    Data tmpData;

    cin >> n;
    while(n --)
    {
        cin >> tmpData;
        mylist.Insert(tmpData);
    }

    mylist.CalcAvg();
    mylist.Sort();

    cout << mylist;

    return 0;
}
