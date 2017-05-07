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
    for(int i=0;i<6;i++){
        cin >> s[i].no >> s[i].sa;
    }
    qsort(s,6,sizeof(a),cmp);
    for(int i=0;i<6;i++){
        cout << s[i].no << endl << s[i].sa << endl;
    }
    return 0;
}
