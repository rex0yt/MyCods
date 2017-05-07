#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    double x,sum=0;

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        sum+=x;
    }
    sum/=n;
    printf("%.3f\n",sum);

    return 0;
}
