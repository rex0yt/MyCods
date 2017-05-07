#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 10000+20

int main()
{
    int m,n;
    int a[N],b[N];
    cin >> n;
    for(int i=0; i<n; i++)cin>>a[i];
    cin >> m;
    for(int i=0; i<m; i++)cin>>b[i];
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(a[i]<b[j])
        {
            cout << a[i] << endl;
            i++;
        }
        else
        {
            cout << b[j] << endl;
            j++;
        }
    }
    if(i==n&&j<m){
        for(;j<m;j++)cout << b[j] << endl;
    }else{
        for(;i<n;i++)cout << a[i] << endl;
    }

    return 0;
}
