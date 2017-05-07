#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 2000+10

int main()
{
    int a;
    int b;
    int c;
    int v;
    for(int i=100;i<=999;i++)
    {
        a=i/100;
        b=i%100/10;
        c=i%10;
        if(i==a*a*a+b*b*b+c*c*c)cout << i << endl;
    }

    return 0;
}
