#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    float x;
    cin >> x;
    if(x<0)x*=(-1);
    else if(x<10)x*=x;
    else x=sqrt(x);

    printf("%.3f\n",x);

    return 0;
}
