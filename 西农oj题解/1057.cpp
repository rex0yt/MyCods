#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200

int main()
{
    float a[N];
    float i=1,j=2;
    for(int k=1;k<=150;k++)
    {
        a[k]=j/(float)i;
        j+=i;
        i=j-i;
    }
    float sum=0;
    int n;
    cin >> n;
    for(int k=1;k<=n;k++)
        sum+=a[k];
    printf("%.3f\n",sum);

    return 0;
}
