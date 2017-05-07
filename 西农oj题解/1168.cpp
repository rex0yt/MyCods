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
    if(m!=n){
        cout << "No\n" ;
        return 0;
    }else{
        sort(a,a+m);
        sort(b,b+m);
        int i;
        for(i=0;i<m;i++){
            if(a[i]!=b[i])break;
        }
        if(i!=m){
            cout << "No\n" ;
            return 0;
        }
        cout << "Yes\n";
    }

    return 0;
}
