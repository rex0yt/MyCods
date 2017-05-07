#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200

int main()
{
    char s[N];
    gets(s);
    for(int i=strlen(s)-1;i>=0;i--)
    {
        cout << s[i];
    }
    cout << endl;

    return 0;
}
