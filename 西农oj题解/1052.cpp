#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200

int main()
{
    int a,b;
    scanf("%d:%d",&a,&b);
    float f1=(a*60+b)*0.5;
    float f2=b*6.0;
    float x=f1-f2;
    if(x<0)x+=360;
    if(x>180)x=360-x;
    printf("%.3f\n",x);

    return 0;
}
