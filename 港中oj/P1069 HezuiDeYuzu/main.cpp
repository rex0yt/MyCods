#include <iostream>
#include <string.h>

#define N 10000+100

using namespace std;

int main()
{
    int a[N];
    int n;
    memset(a,0,sizeof(a));

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j%i == 0)
                a[j] = a[j]? 0: 1;
        }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++)
        if(a[i])cnt ++;

    cout<< cnt << endl;
    return 0;
}
