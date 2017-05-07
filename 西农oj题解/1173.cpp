#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

struct A{
    char name[25];
    char count[2000];
};

int cmp(const void *p,const void *q){
    const A *a=(A*)p;
    const A *b=(A*)q;
    if(strlen(a->count) < strlen(b->count))
        return 1;
    else if(strlen(a->count) > strlen(b->count))
        return -1;
    else{
        int i;
        for(i=0;i<strlen(a->count);i++)
            if(a->count[i]!=b->count[i])
                break;
        if(a->count[i] < b->count[i])return 1;
        else if(a->count[i] > b->count[i])return -1;
    }
    return strcmp(a->name,b->name);
}

int main()
{
    A arr[N];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i].name >> arr[i].count;
    }
    qsort(arr,n,sizeof(A),cmp);

    for(int i=0;i<n;i++){
        cout << arr[i].name << endl;
    }
    return 0;
}
