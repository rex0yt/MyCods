#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool isprime(int i)
{
    for(int j=2;j<=(int)sqrt(i);j++)
        if(i%j==0)return 0;
    return 1;
}
int main()
{
    int m,n;

    cin >> m >> n;

    for(int i=m;i<=n;i++)
    {
        if(isprime(i))cout << i << endl;
    }

    return 0;
}
