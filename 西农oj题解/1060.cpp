#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200

int main()
{
    int a=0,b=0,c=0,d=0,e=0;
    char s[N];
    for(int i=0;i<3;i++)
    {
        gets(s);
        for(int j=0;j<strlen(s);j++)
        {
            if('A'<=s[j]&&'Z'>=s[j])a++;
            else if('a'<=s[j]&&'z'>=s[j])b++;
            else if('0'<=s[j]&&'9'>=s[j])c++;
            else if(' '==s[j])d++;
            else e++;
        }
    }
    cout << a << endl << b << endl
        << c << endl << d << endl << e << endl;
    return 0;
}
