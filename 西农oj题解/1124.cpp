#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 2000+10

int main()
{
    int a=0,b=0,c=0,d=0,e=0;
    char s[N];

        gets(s);
        for(int j=0;j<strlen(s);j++)
        {
            if('a'<=s[j]&&'z'>=s[j])b++;
            else if(' '==s[j])d++;
            else e++;
        }

    cout << b << endl
         << d << endl << e << endl;
    return 0;
}
