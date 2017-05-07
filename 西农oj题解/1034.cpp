#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char ch[30];
    cin >> ch;
    for(int i=0;i<strlen(ch);i++)
    {
        if('A'<=ch[i]&&ch[i]<='Z')ch[i]+=32;
        else if('a'<=ch[i]&&ch[i]<='z')ch[i]-=32;
    }
    cout << ch << endl;

    return 0;
}
