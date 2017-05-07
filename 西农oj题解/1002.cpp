#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int a[20000];

    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n-1);
    for(int i=0;i<n;i++)cout << a[i] << endl;

    return 0;
}
