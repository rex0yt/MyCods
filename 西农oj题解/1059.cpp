#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 10000+20

int main()
{
    int n;
    int a[N];
    int x;
    int f;

    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    if(a[0]<a[n-1])f=1;else f=0;
    cin >> x;
    a[n++]=x;

    sort(a,a+n);
    if(f)for(int i=0;i<n;i++)cout << a[i] << endl;
    else for(int i=n-1;i>=0;i--)cout << a[i] << endl;

    return 0;
}
