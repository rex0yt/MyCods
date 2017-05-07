#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{
    int a=0,b=0;
    char s[N];

        gets(s);
        for(int j=0;j<strlen(s);j++)
        {
            if('A'<=s[j]&&'Z'>=s[j])a++;
            else if('a'<=s[j]&&'z'>=s[j])b++;
        }

    cout << abs(b-a) << endl;
    return 0;
}
