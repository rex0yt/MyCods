#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

struct a{
    char no[20];
    char sa[20];
};

int cmp(const void *p,const void*q){
    a *x=(a*)p;
    a *y=(a*)q;
    return strcmp(x->no,y->no);
}

int main()
{
    a s[N];
    int i;
    char m[5];
    for(int i=0;i<5;i++){
        cin >> s[i].no >> s[i].sa;
    }
    cin >> m;
    for(i=0;i<5;i++)
        if(strcmp(s[i].no,m)==0)break;
    strcpy(s[i].no,"999");
    qsort(s,5,sizeof(a),cmp);
    for(int i=0;i<4;i++){
        cout << s[i].no << endl << s[i].sa << endl;
    }
    return 0;
}
