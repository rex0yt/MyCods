#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{
    int n;
    double x,sum=1,f=1;
    cin >> n >> x;
    double m=x;

    for(int i=1;i<=n;i++)
    {
        sum+=m/f;
        m*=x;
        f*=i+1;
    }
    printf("%lf\n",sum);
    return 0;
}
