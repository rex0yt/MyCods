#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s1[50],s2[50];
    gets(s1);
    gets(s2);
    for(int i=0;i<strlen(s1);i++)
        cout << s1[i];
    for(int i=0;i<strlen(s2);i++)
        cout << s2[i];
    cout << endl;
    return 0;
}
