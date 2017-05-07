#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int main()
{
    int m,n;
    int i=0;

    int a[100];
    cin >>m;
    for(;i<m;i++)
        cin >> a[i];
    cin >> n;
    for(;i<m+n;i++)
        cin >> a[i];
    sort(a,a+m+n);
    for(i=0;i<m+n;i++)
        cout << a[i] << endl;
}
