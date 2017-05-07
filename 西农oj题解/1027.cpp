#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{

    int a;
    cin >> a;
    if(a>=90)cout << "A\n";
    else if(a>=80)cout << "B\n";
    else if(a>=60)cout << "C\n";
    else cout << "D\n";
    return 0;
}
