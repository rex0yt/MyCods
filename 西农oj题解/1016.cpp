#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a[300];
    memset(a,0,sizeof(a));
    char s[300];
    cin >> s;
    int h1=0,h2=0;
    for(int i=0;i<strlen(s);i++)
    {
        a[s[i]]++;
    }
    for(int i='a';i<='z';i++)
        if(a[i]!=0)h1++;
    for(int i='A';i<='Z';i++)
        if(a[i]!=0)h2++;
    cout << h2 << endl << h1 << endl;

    return 0;
}
