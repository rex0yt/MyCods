#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int t = 0;
    long long n = 2,vleft,x;

    while(t < 10){
        vleft = n*(n + 1) / 2;
        x = (long long)sqrt(vleft);
        if(x*x == vleft){
            printf("%10lld%10lld\n",x,n);
            t ++;
        }
        n ++;
    }
    return 0;
}
