#include <iostream>
#include <stdio.h>

#define N 20000+100 //1≤ N≤20000
using namespace std;

short father[N];
int n, m;

void init()
{
    for(int i=0; i<N; i++)
        father[i] = i;
}

int ifind(int i)
{
    if(i != father[i])
        father[i] = ifind(father[i]);
    return father[i];
}

void iunion(int i,int j)
{
    int x = ifind(i);
    int y = ifind(j);
    if(x == y)return ;
    father[x] = y;
}

int main()
{
    int tmp0,tmp1;

    init();
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&tmp0,&tmp1);
        iunion(tmp0, tmp1);
    }
    scanf("%d",&m);
    while(m --)//则输出“Yes”，否则输出“No”
    {
        scanf("%d %d",&tmp0,&tmp1);
        if(ifind(tmp0) == ifind(tmp1))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
