#include <iostream>
#include <stdio.h>
#include <queue>

#define N (1000+100)

using namespace std;

class point
{
public:
    int x;
    int y;
};

class node:public point
{
public:
    int father;
    node(point tmp)
    {
        this->x = tmp.x;
        this->y = tmp.y;
        father = -1;
    }
    node()
    {

    }
};

bool imap[N][N];
int ansmap[N][N];
int m, n, pnt_x, pnt_y;
int dir_x[] = {-2,-1,1,2,2,1,-1,-2};
int dir_y[] = {1,2,2,1,-1,-2,-2,-1};
point ibegin, tmp;

void init()
{
    for(int i=0; i<=n; i++)
        imap[i][0] = imap[i][m+1] = 1;
    for(int i=0; i<=m; i++)
        imap[0][i] = imap[n+1][i] = 1;
}

bool check(point &dot)
{
    if(dot.x <= 0 || dot.x > n)return false;
    if(dot.y <= 0 || dot.y > m)return false;
    if(imap[dot.x][dot.y])return false;
    return true;
}
bool dfs(node thisnode, int cnt)
{
    bool flag = false;
    if(cnt+1 == m*n)
    {
        ansmap[thisnode.x][thisnode.y] = cnt;
        return true;
    }
    imap[thisnode.x][thisnode.y] = 1;
    for(int i=0; i<8; i++)
    {
        tmp.x = thisnode.x + dir_x[i];
        tmp.y = thisnode.y + dir_y[i];
        if(check(tmp))
        {
            if(dfs(tmp, cnt+1))
            {
                ansmap[thisnode.x][thisnode.y] = cnt;
                //cout<<thisnode.x<<' '<<thisnode.y<<endl;
                return true;
            }
        }
    }
    imap[thisnode.x][thisnode.y] = 0;
    return false;
}

int main()
{

    cin>>n>>m>>ibegin.x>>ibegin.y;
    init();
    dfs(ibegin, 0);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            printf("%d ",ansmap[i][j]);
        }
        printf("\n");
    }
    return 0;
}
