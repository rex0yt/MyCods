#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{
    int n;
    int x,count;
    int a;
    cin >> n;
    while(n--)
    {
        cin >> x;
        count =0;
        a=5;
        while(a<=x)
        {
            count += x/a;
            a*=5;
        }
        cout << count << endl;
    }
    return 0;
}
