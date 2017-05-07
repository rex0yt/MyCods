#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s[10];
    int sum=0;

    cin >> s;
    for(int j=0;j<8;j++)
    {
        sum*=2;
        sum+=s[j]-'0';
    }
    cout << sum << endl;

    return 0;
}
