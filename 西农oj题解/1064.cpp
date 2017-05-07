#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int main()
{
    int a[4][4];
    int sum1=0,sum2=0,max=-999;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin >> a[i][j];
            if(max<a[i][j])max=a[i][j];
        }
    }
    for(int i=0;i<4;i++)
    {
        sum1+=a[i][i];
        sum2+=a[i][3-i];
    }
    cout << sum1 << endl << sum2 << endl << max << endl;


    return 0;
}
