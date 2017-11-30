using namespace std;
/*
 * travel a map in two ways
 * input:
 *      1. n:
 *      2.matrix (n*n)
 * output:
 *      DFS
 *      WFS
 */
#include <iostream>
#include <cstring>
#include <queue>
#define MaxN 1000

int thisMap[MaxN][MaxN];
int n;
int thisDFS[MaxN][MaxN];
int thisBFS[MaxN][MaxN];
bool visted[MaxN];

bool InputData()
{
    cin >> n;       //input n
    for(int i=0; i<n; i++) // input matrix(n*n)
    {
        for(int j=0; j<n; j++)
        {
            cin >> thisMap[i][j];
        }
    }
    return true;
}

void DFS(int x)
{
    visted[x] = true;
    cout << x << " ";

    for(int i=0; i<n; i++)
    {
        if(thisMap[x][i] && visted[i]==false)
        {
            DFS(i);
        }
    }
}

void BFS(int x)
{
    memset(visted, 0, sizeof(visted));
    queue<int> myQ;
    myQ.push(x);
    visted[x] = true;
    while(myQ.size())
    {
        int tmp = myQ.front();
        myQ.pop();
        cout << tmp << " ";
        for(int i=0; i<n; i++)
        {
            if(visted[i]==false && thisMap[tmp][i]==1)
            {
                visted[i] = true;
                myQ.push(i);
            }
        }
    }
    cout << endl;
}

int main()
{
    InputData(); // input the data
    for(int i=0; i<MaxN; i++)
    {
        for(int j=0; j<MaxN; j++)
        {
            thisBFS[i][j] = 0;
            thisDFS[i][j] = 0;
        }
    }
    cout << "DFS" << endl;
    for(int i=0; i<n; i++)
    {
        memset(visted, 0, sizeof(visted));
        DFS(i);
        cout << endl;
    }
    cout << "WFS" << endl;
    for(int i=0; i<n; i++)
    {
        BFS(i);
    }
    return 0;
}