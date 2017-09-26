#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const int defaultSize=1000;
const int N = 100;

template<typename T>
class Stack
{
private:
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
        if(!IsFull())
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
    bool IsFull()const
    {
        return top==maxSize-1;
    }
    int GetSize()const
    {
        return top+1;
    }
    void MakeEmpty()
    {
        top=-1;
    }
};

class Point{
    int x;
    int y;
public:
    friend ostream& operator<<(ostream& os, const Point& left)
    {
        os << left.x << " " << left.y << endl;
        return os;
    }
};
int imap[N][N];
int dirx[] = {1, 0, -1, 1};
int diry[] = {0, -1, 1, 0};
int n, m;
int beg_x,beg_y,end_x,end_y;
int tmp;

bool init()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> tmp;
            if(tmp > 1)
            {
                if(tmp == 3)
                {
                    beg_x = i;
                    beg_y = j;
                }
                else
                {
                    end_x = i;
                    end_y = j;
                }
            }
            if(tmp != 1)imap[i][j] = 0;
        }
    }
    for(int i=0; i<m; i++)
        imap[0][i] = imap[n+1][i] = 1;
    for(int i=0; i<n; i++)
        imap[0][i] = imap[m+1][i] = 1;

    return true;
}
bool solve()
{

    return true;
}

int main()
{

    init();
    solve();

    return 0;
}
