#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200

int main()
{
    char a[4][N];
    char tmp[N];
    int x;

    for(int i=0;i<4;i++)
        cin >> a[i];
    for(int i=0;i<3;i++)
    {
        x=i;
        for(int j=i;j<4;j++)
            if(strcmp(a[x],a[j])>0)x=j;
        strcpy(tmp,a[i]);
        strcpy(a[i],a[x]);
        strcpy(a[x],tmp);
    }
    for(int i=0;i<4;i++)
        cout << a[i] << endl;

    return 0;
}
