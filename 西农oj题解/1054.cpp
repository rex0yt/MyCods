#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int main()
{
    int a=0,b=0,c=0,d=0;
    char s[1000];
    gets(s);
    for(int i=0; i<strlen(s); i++)
    {
        if('a'<=s[i]&&s[i]<='z')a++;
        else if('A'<=s[i]&&s[i]<='Z')a++;
        else if('0'<=s[i]&&s[i]<='9')b++;
        else if(' '==s[i])c++;
        else d++;
    }
    cout << a << " " << c << " " << b << " " << d <<endl;

    return 0;
}
