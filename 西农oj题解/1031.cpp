#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int a[N];

int abc(int n)
{
    if(a[n]!=0)return a[n];
    return n*abc(n-1);
}

int main()
{
    memset(a,0,sizeof(a));
    a[1]=1;
    int n,sum=0;
    cin >> n;
    for(int i=1;i<=n;i++)
        sum+=abc(i);
    cout << sum << endl;
    return 0;
}
