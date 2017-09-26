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
    ListNode(Type _data=0, ListNode<Type> *_next=NULL)
        :data(_data),next(_next)
    {

    }
    ListNode& operator=(const ListNode<Type>& left)
    {
        this->data = left.data;
        this->next = left.next;
        return *this;
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
                os << pnt->data << " ";
                pnt = pnt->next;
            }
        }
        os << endl;
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
    bool Delete(int index)
    {
        ListNode<Type> *tmpPnt = first, *pre;
        if(index <=0 || index >size)
        {
            return false;
        }
        if(index == 1)
        {
            first = first->next;
            delete tmpPnt;
            size --;
            return true;
        }
        while(-- index)
        {
            pre = tmpPnt;
            tmpPnt = tmpPnt->next;
        }

        pre->next = tmpPnt->next;
        delete tmpPnt;
        size --;
        return true;
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
    bool Reverse()
    {
        Type tmp;
        for(int i=1; i<=size/2; i++)
        {
            tmp = this->operator[](i)->data;
            this->operator[](i)->data = (this->operator[](size+1-i))->data;
            (this->operator[](size+1-i))->data = tmp;
        }
        return true;
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
    bool HeBing(const LinkedList<Type>& left)
    {
        ListNode<Type> *pnt = left.first;
        while(pnt)
        {
            int index = this->LowBound(*pnt);
            this->Insert(*pnt, index);
            pnt = pnt->next;
        }
        return true;
    }
};
int main()
{
//    freopen("data.txt","r",stdin);

    int n;
    int tmp, index;
    ListNode<int> tmpNode;
    LinkedList<int> mylist, newlist;

    cin >> n;//input the first list
    while(n --)
    {
        cin >> tmp;
        tmpNode.data = tmp;
        mylist.Insert(tmpNode);
    }
//    cout << mylist;

    cin >> tmp >> index;//insert one element
    tmpNode.data = tmp;
    mylist.Insert(tmpNode, index);
    cout << mylist;

    cin >> index;//delete one element
    mylist.Delete(index);
    cout << mylist;

    cin >> tmpNode.data;//search one element
    if(mylist.Search(tmpNode) == 0)
        cout << "Not found";
    else
        cout << mylist.Search(tmpNode);
    cout << endl;

    mylist.Reverse();//reverse
    cout << mylist;

    cin >> n;//input anthor list
    while(n --)
    {
        cin >> tmpNode.data;
        newlist.Insert(tmpNode);
    }
    mylist.HeBing(newlist);//HeBing
    cout << mylist;

    return 0;
}
