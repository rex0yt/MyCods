#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 100+10

using namespace std;

int arr[N];
int n;
int ltor[N],rtol[N],sol[N];

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    memset(ltor,0,sizeof(ltor));
    memset(rtol,0,sizeof(rtol));


    for(int i=0; i<n; i++)
    {
        ltor[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j])
                ltor[i] = max(ltor[j]+1,ltor[i]);
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        rtol[i] = 1;
        for(int j=n-1; j>i; j--)
        {
            if(arr[i] > arr[j])
                rtol[i] = max(rtol[j]+1,rtol[i]);
        }
    }
    for(int i=0; i<n; i++)
        sol[i] = ltor[i] + rtol[i];

    int pmax = -999;
    for(int i=0; i<n; i++)
        pmax = max(pmax, sol[i]);

    cout << n - pmax + 1 << endl;
    return 0;
}
