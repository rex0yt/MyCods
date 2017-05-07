#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 100+20

int main()
{
    int m,n;
    cin >> m >> n;
    int a[N][N];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    int count=0;
    for(int i=1;i<m-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(a[i][j]<a[i][j-1]&&a[i][j]<a[i][j+1]&&a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j])count ++;
        }
    }
    printf("%d\n", count);
    return 0;
}
