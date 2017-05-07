#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{
    int a,c,b;
    cin >> a >> b >> c;
    if(a>b&&a>c)cout << a << endl;
    else if(b>c&&b>a)cout << b << endl;
    else cout << c << endl;

    return 0;
}
