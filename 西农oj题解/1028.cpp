#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200


int main()
{
    float a,b,c;
    cin >> a >> b >> c;
    if(a+b>c&&a+c>b&&b+c>a)
        cout << "Y\n";
    else cout << "N\n";

    return 0;
}
