#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{
    int a[N];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
