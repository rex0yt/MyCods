#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int abc(int a,int n){
    int s=1;
    for(int i=0;i<n;i++)
    {
        s*=a;
    }
    return s;
}
int main(){
    double b,n,h;
    cin>>b>>n;
    h=b;
    while(b!=0||n!=0){
        h=log(b)/n;
        h=exp(h);
        int a1 = (int)h;
        int a2 = a1+1;
        if((b-abc(a1,n))<(abc(a2,n)-b))
            cout<<a1<<endl;
        else
            cout<<a2<<endl;
        cin>>b>>n;
    }

    return 0;
}
