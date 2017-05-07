#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s[50];
    char ch;
    int i=0;
    cin >> s >> ch;
    for(;i<strlen(s);i++)
        if(s[i]==ch)break;
    if(i==strlen(s))cout << -1;
    else cout << i+1;

    cout << endl;

    return 0;
}
