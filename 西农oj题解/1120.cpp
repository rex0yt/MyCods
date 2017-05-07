#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{
    int a=0,b=0,c=0;
    char s[1000];
    gets(s);
    for(int i=0; i<strlen(s); i++)
    {
        if('A'<=s[i]&&s[i]<='Z')a++;
        else if('0'<=s[i]&&s[i]<='9')b++;
        //else if(' '==s[i])c++;
        else c++;
    }
    cout << a << endl << b << endl << c  <<endl;

    return 0;
}
