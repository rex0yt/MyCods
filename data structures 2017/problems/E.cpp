#include <iostream>
#include <cstdio>

using namespace std;
const int defaultSize=1000000;
const int N = 1000;

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

class Point{
public:
    int row;
    int col;
public:
    Point(int _row=0,int _col=0):row(_row),col(_col) {}
    friend ostream& operator<<(ostream& os, const Point& left)
    {
        os << left.col << " " << left.row << endl;
        return os;
    }
};
class StackNode:public Point
{
public:

    int dir;
public:
    StackNode(Point &point, int _dir)
        :Point(point),dir(_dir) {}
    StackNode() {}
    friend ostream& operator<<(ostream& os,const StackNode& left)
    {
        os << left.col << " " << left.row << endl;
        return os;
    }
};

int imap[N][N];
int dirrow[] = {0, 1, 0, -1, 0};
int dircol[] = {0, 0, -1, 0, 1};
int col, row;
Stack<StackNode> myStack;
Point ibeg,iend;

bool Move(StackNode& thisnode, StackNode& nextnode)
{
    if(thisnode.dir == 5)return false;
    nextnode.dir = 0;
    for(++thisnode.dir; thisnode.dir<=4; thisnode.dir++)
    {
        nextnode.row = thisnode.row + dirrow[thisnode.dir];
        nextnode.col = thisnode.col + dircol[thisnode.dir];
        if(imap[nextnode.row][nextnode.col] == 0)
        {
            imap[nextnode.row][nextnode.col] = 1;
            return true;
        }
    }
    return false;
}
bool init()
{
    int tmp;

    cin >> col >> row;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> tmp;
            if(tmp > 1)
            {
                if(tmp == 3)
                {
                    ibeg.row = i;
                    ibeg.col = j;
                }
                else
                {
                    iend.row = i;
                    iend.col = j;
                }
            }
            if(tmp == 1)imap[i][j] = 1;
            else imap[i][j] = 0;
        }
    }

    return true;
}

bool solve()
{
    StackNode thisPoint, NextPoint;
    thisPoint.row = ibeg.row;
    thisPoint.col = ibeg.col;
    thisPoint.dir = 0;  //haven't tried any way
    imap[ibeg.row][ibeg.col] = 1;

    while(1)
    {
        if(Move(thisPoint, NextPoint))//move to next point
        {
            myStack.Push(thisPoint);
            thisPoint = NextPoint;
            if(thisPoint.row==iend.row && thisPoint.col==iend.col)break;
        }
        else//cannot move to new point
        {
            if(myStack.IsEmpty())break;
            myStack.GetTop(thisPoint);
            myStack.Pop();
        }
    }
    return true;
}
bool PrintWay()
{
    if(myStack.IsEmpty())return false;
    for(int i=0; i<myStack.GetSize(); i++)
    {
        cout << myStack.data[i];
    }
    cout << iend;
    return true;
}
int main()
{
//    freopen("data.txt", "r", stdin);
    init();
    solve();
    PrintWay();

    return 0;
}
