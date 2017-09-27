#include <iostream>

using namespace std;

class Data
{
    string str;
public:
    friend istream& operator>>(istream& is, Data& data)
    {
        getline(is, data.str);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Data& left)
    {
        cout << left.str << endl;
        return os;
    }
};

template<typename Type>
class ListNode
{
public:
    Type data;
    ListNode<Type> *next;
public:
    ListNode() {}
    ListNode(Type& _data, ListNode<Type>& _next=NULL)
    {
        data = _data;
        next = _next;
    }
    friend ostream& operator<<(ostream& os, const ListNode& left)
    {
        os << left.data;
        return os;
    }
};

template<typename Type>
class LinkedStack
{
    ListNode<Type>* top;
    int size;
public:
    LinkedStack()
    {
        top = NULL;
        size = 0;
    }
    ~LinkedStack(){
        while(!IsEmpty()){
            Pop();
        }
    }

    bool Push(const Type &data)
    {
        ListNode<Type> *pnt;
        pnt = new ListNode<Type>;
        pnt->data = data;
        pnt->next = top;
        top = pnt;
        size ++;
        return true;
    }

    Type Top()
    {
        return top->data;
    }

    Type Pop()
    {
        ListNode<Type> tmp;
        tmp.data = top->data;
        ListNode<Type> *pnt = top;
        top = pnt->next;
        delete pnt;
        size --;
        return tmp.data;
    }

    bool IsEmpty()
    {
        return top==NULL;
    }
};

template<typename Type>
class LinkedList
{
private:
    ListNode<Type> *first, *last;
    int size;
public:
    LinkedList()
    {
        first = last = NULL;
        size = 0;
    }

    bool Insert(const Type& data)
    {
        ListNode<Type> *pnt;
        pnt = new ListNode<Type>;
        pnt->data = data;

        if(first == NULL)
        {
            first = last = pnt;
            first->next = NULL;
            size = 1;
            return true;
        }
        pnt->next = last->next;
        last->next = pnt;
        last = pnt;
        size ++;
        return true;
    }

//    bool Delete(Type &data)
//    {
//        if(first == NULL)
//            return false;
//
//        data = first->data;
//        if(first == last){
//            delete first;
//            last = NULL;
//            size = 0;
//            return true;
//        }
//        ListNode<Type> *pnt = first;
//        first = first->next;
//        delete pnt;
//        size --;
//        return true;
//    }

    bool Reverse()
    {
        if(first == NULL)return false;

        LinkedStack<ListNode<Type>*> myStack;
        ListNode<Type> *pnt;
        pnt = first;
        while(pnt)
        {
            myStack.Push(pnt);
//            cout << pnt->data;
            pnt = pnt->next;
        }

        ListNode<Type>* tmp = myStack.Pop();
//        cout << tmp->data;
        first = last = tmp;
        first->next = NULL;
        while(!myStack.IsEmpty())
        {
            tmp = myStack.Pop();
//            cout << tmp->data;
            tmp->next = last->next;
            last->next = tmp;
            last = tmp;
        }
        return true;
    }

    friend ostream& operator<<(ostream& os, const LinkedList& left)
    {
        ListNode<Type> *pnt = left.first;
        while(pnt)
        {
            cout << pnt->data;
            pnt = pnt->next;
        }
        return os;
    }
};
int main()
{
//    freopen("data.txt", "r", stdin);

    int n;
    Data tmpData;
    string tmp;
    LinkedList<Data> myList;
    LinkedStack<Data> myStack;

    cin >> n;
    getline(cin,tmp);
    for(int i=0; i<n; i++)
    {
        cin >> tmpData;
        myList.Insert(tmpData);
    }
//    cout << myList;
    myList.Reverse();
    cout << myList;

    return 0;
}
