#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int abc(int a,char *s){
    int i=0;
    while(a!=0){
        s[i++]=a%2+'0';
        a/=2;
    }
    s[i]='\0';
}
int main()
{
    int n;
    char s[N];
    cin >> n;
    abc(n,s);
    for(int i=strlen(s)-1;i>=0;i--)cout<< s[i];
    cout << endl;
    return 0;
}
