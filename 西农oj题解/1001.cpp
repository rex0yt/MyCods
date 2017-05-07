#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 10000+20
int arr[N];

int find(int a,int b,int x)
{
    int f;
    if(a>b)return 0;
    else if(a==b){
        if(arr[a]==x)return 1;
        else return 0;
    }
    else {
        int mid = (a+b)/2;
        if(x==arr[mid])return 1;
        else if(x<arr[mid])f=find(a,mid-1,x);
        else f=find(mid+1,b,x);
    }
    if(f)return 1;
    return 0;
}
int main()
{
    int n,x;
    cin >> n;
    for(int i=0;i<n;i++)cin >> arr[i];
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> x;
        if(find(0,n,x))cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
