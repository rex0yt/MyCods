#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int main()
{
    int m;
    int a[20][20];

    cin >> m;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(j==i)
            {
                a[i][j]=1;
                cout << 1 << endl;
            }
            else if(1==j)
            {
                a[i][j]=1;
                cout << 1 << " " ;
            }
            else
            {
                a[i][j] = a[i-1][j-1]+a[i-1][j];
                cout << a[i][j] << " ";
            }
        }
    }

    return 0;
}
