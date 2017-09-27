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
    friend ostream& operator<<(ostream &os, const ListNode& left)
    {
        os << left.data;
        return os;
    }
};

template <typename Type>
class LinkedQueue
{
private:
    ListNode<Type> *first, *last;
    int size;
public:
    LinkedQueue():first(NULL),last(NULL),size(0) {}

    bool PushBack(const Type& left)
    {
        ListNode<Type> *pnt = new ListNode<Type>;
        pnt->data = left;
        pnt->next = NULL;

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

    bool Pop(Type& left)
    {
        ListNode<Type> *tmpPnt = first;

        if(IsEmpty())
            return false;

        if(first == last)
            last = tmpPnt->next;

        first = tmpPnt->next;
        left = tmpPnt->data;

        delete tmpPnt;
        size --;

        return true;
    }

    bool IsEmpty()
    {
        return first==NULL;
    }
};
int main()
{
//    freopen("data.txt","r",stdin);
    char ch;
    int no;
    LinkedQueue<int> myQueue;

    while(cin >> ch)
    {
        switch(ch)
        {
        case 'A':case 'a':
            cin >> no;
            myQueue.PushBack(no);
            break;
        case 'N':case 'n':
            if(myQueue.IsEmpty())
                cout << "无病人就诊" << endl;
            else
            {
                myQueue.Pop(no);
                cout << "病历号为" << no << "的病人就诊" << endl;
            }
            break;
        case 'S':case 's':
            cout << "今天不再接收病人排队，下列排队的病人依次就诊：";
            while(!myQueue.IsEmpty())
            {
                myQueue.Pop(no);
                cout << no << " ";
            }
            cout << endl;
            break;
        default:
            cout << "输入命令不合法！" << endl;
            break;
        }

    }


    return 0;
}
