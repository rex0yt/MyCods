#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int cmp(const void *p,const void *q){
    const char *a=(char*)p;
    const char *b=(char*)q;
    return strcmp(a,b);
}
int main()
{
    int n;
    char s[N][22];
    cin >> n;
    for(int i=0;i<n;i++)cin>>s[i];
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)cout<<s[i]<<endl;
    return 0;
}
