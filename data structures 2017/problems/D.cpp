#include <iostream>
#include <cstdio>

using namespace std;

template <typename Type>
class ListNode
{
public:
    Type data;
    ListNode<Type> *next;
public:
    ListNode() { }
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
    friend ostream& operator<<(ostream& os, const ListNode<Type>& left)
    {
        os << left.data;
        return os;
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
            last = first = pnt;
            pnt->next = first;
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

    friend ostream& operator<<(ostream &os, const LinkedList<Type> &left)
    {
        ListNode<Type> *pnt = left.first;
        if(left.first == NULL)
        {

        }
        else
        {
            os << pnt->data;
            pnt = pnt->next;
            while(pnt != left.first)
            {
                os << pnt->data;
                pnt = pnt->next;
            }
        }
        return os;
    }

    bool Josef(int m)
    {
        ListNode<Type> *pnt=first, *pre;

        for(int i=0; i<m-1; i++)
        {
            pre = pnt;
            pnt = pnt->next;
        }
        cout << *pnt;
        pre->next = pnt->next;
        delete pnt;
        size --;

        while(first)
        {
            if(size == 0)break;
            for(int i=0; i<m; i++)
            {
                pre = pnt;
                pnt = pnt->next;
            }
            cout << *pnt;
            pre->next = pnt->next;
            delete pnt;
            size --;
        }
        return true;
    }

};
class Data
{
public:
    string info;
public:
    friend istream& operator>>(istream& is, Data& left)
    {
        getline(is, left.info);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Data &left)
    {
        cout << left.info << endl;
        return os;
    }
};

int main()
{
//    freopen("data.txt", "r", stdin);

    int n, m;
    LinkedList<Data> mylist;
    Data tmpData;

    cin >> n >> m;//input data
    getchar();
    while(n --)
    {
        cin >> tmpData;
        mylist.Insert(tmpData);
    }
//    cout << mylist;
    mylist.Josef(m);//Josef

    return 0;
}
