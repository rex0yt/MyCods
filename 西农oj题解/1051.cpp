#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    if(a>=20)
    {
        if(b>2000)b+=200;
        else b+=180;
    }
    else
    {
        if(b>1500)b+=150;
        else b+=120;
    }
    cout << b<< endl;
    return 0;
}
