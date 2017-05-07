#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200

int c[N][N];
int knapsack(int n,int m)
{
    int i,j,w[N],p[N];

    for(i=1; i<n+1; i++)
        scanf("%d",&w[i]);
    for(i=1; i<n+1; i++)
        scanf("%d",&p[i]);

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            c[i][j]=0;

    for(i=1; i<n+1; i++)
        for(j=1; j<m+1; j++)
        {
            if(w[i]<=j)
            {
                if(p[i]+c[i-1][j-w[i]]>c[i-1][j])
                    c[i][j]=p[i]+c[i-1][j-w[i]];
                else
                    c[i][j]=c[i-1][j];
            }
            else
                c[i][j]=c[i-1][j];
        }
    return(c[n][m]);
}
int main()
{
    int c,n;
    scanf("%d %d",&n,&c);
    while(!(c==0&&n==0))
    {
        printf("%d\n",knapsack(n,c));
        scanf("%d %d",&n,&c);
    }
    return 0;
}
