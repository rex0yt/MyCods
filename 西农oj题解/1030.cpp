#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{

    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    return 0;
}
