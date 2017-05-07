#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int x[N];
int y[N];
float f1,f2,f3;

int abc(){
    if(f1+f2==f3||f1+f3==f2||f2+f3==f1)
        return 1;
    return 0;
}

int main()
{
    cin >> x[0]>> y[0]
        >> x[1]>> y[1]
        >> x[2]>> y[2];
    int a=0,b=1,c=2;
    f1=(y[b]-y[a])*(y[b]-y[a])+(x[b]-x[a])*(x[b]-x[a]);
    f2=(y[c]-y[a])*(y[c]-y[a])+(x[c]-x[a])*(x[c]-x[a]);
    f3=(y[b]-y[c])*(y[b]-y[c])+(x[b]-x[c])*(x[b]-x[c]);
    if(abc())
        cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
