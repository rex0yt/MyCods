#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d/%d %d/%d",&a,&b,&c,&d);

    if(a*d > b*c)
    {
        cout << "Y\n";
    }
    else
    {
        cout << "N\n";
    }

    return 0;
}
