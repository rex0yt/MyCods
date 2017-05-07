#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 2000+10

int main()
{
    char s[N];
    cin >> s;
    int val=0;
    for(int i=0;i<strlen(s)-1;i++)
        val+=(i+1)*(s[i]-'0');
    val%=11;
    if(s[strlen(s)-1]-'0'==val)cout <<"Yes\n";
    else if(val==10&&s[strlen(s)-1]=='Y')cout <<"Yes\n";
    else cout << "No\n";

    return 0;
}
