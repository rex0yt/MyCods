#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 2000


int main()
{
    bool s[N];
    memset(s,0,sizeof(s));
    int a,b;
    cin >> a >> b;
    s[1]=1;
    for(int i=2;i<=b;i++)
    {
        if(s[i]==0)
        for(int j=i+i;j<=b;j+=i)
            s[j]=1;
    }
    for(int i=a;i<=b;i++)
        if(s[i]==0)cout << i << endl;

    return 0;
}
