#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200

int abc(char *s)
{
    int sum=0;
    for(int j=0;j<8;j++)
    {
        sum*=2;
        sum+=s[j]-'0';
    }
    return sum;
}

int main()
{
    char s[N];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        cout << abc(s) << '.' << abc(s+8) << '.'
            << abc(s+16) << '.' << abc(s+24) << endl;
    }

    return 0;
}
