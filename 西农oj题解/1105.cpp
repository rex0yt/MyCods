#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{
    char s1[N],s2[N];
    gets(s1);
    gets(s2);
    if(strcmp(s1,s2)>0){
        cout << s1 << endl << s1 << s2 << endl;
    }else{
        cout << s2 << endl << s2 << s1 << endl;
    }
    return 0;
}
