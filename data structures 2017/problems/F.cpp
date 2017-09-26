#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
const int defaultSize=10000;

template<typename T>
class Stack
{
public:
    T* data;
    int maxSize;
    int top;

public:
    Stack(int sz=defaultSize)
    {
        maxSize=sz;
        data = new T[maxSize];
        top=-1;
    }
    ~Stack()
    {
        delete []data;
    }
    void Push(const T &x)
    {
        data[++top]=x;
    }
    bool Pop()
    {
        if(top==-1)
            return  false;
        top--;

        return true;
    }
    bool GetTop(T &x)const
    {
        if(top==-1)
            return false;
        x=data[top];
        return true;
    }
    bool IsEmpty()const
    {
        return top==-1;
    }
    int GetSize()const
    {
        return top+1;
    }
};

map<char, int> imap;

bool init()
{
    imap['('] = -1;
    imap[')'] = 1;
    imap['['] = -2;
    imap[']'] = 2;
    imap['{'] = -3;
    imap['}'] = 3;

    return true;
}
int main()
{
    char ch;
    int lens;
    int val, topval;
    Stack<int> myStack;

//    freopen("data.txt", "r", stdin);

    init();

    while(cin>>ch && ch!='#')
    {
        val = imap[ch];
        myStack.GetTop(topval);
        if(val < 0)myStack.Push(val);
        else
        {
            if(val + topval == 0)
                myStack.Pop();
            else
            {
                cout << "²»Æ¥Åä" << endl;
                return 0;
            }
        }
    }
    if(myStack.IsEmpty())
        cout << "Æ¥Åä" << endl;
    else
        cout << "²»Æ¥Åä" << endl;
    return 0;
}
