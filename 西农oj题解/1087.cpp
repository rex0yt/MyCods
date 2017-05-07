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
    char ch;
    ch= getchar();
    for(int i=0;i<(int)strlen(s);i++)
    {
        if(ch!=s[i])cout<<s[i];
    }
    cout << endl;

    return 0;
}
