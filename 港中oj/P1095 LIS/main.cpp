#include <iostream>
#include <stdio.h>

#define N 200000+1000

using namespace std;

int arr[N];
int newarr[N];
int d[N];

int n,k;
int tmp;

int binarySearch(int key,int left,int right)
{
    while(left <= right)
    {
        int mid = (left + right)>>1;

        if(key>d[mid] && key<=d[mid+1])
            return mid;
        else if(key>d[mid])
            left = mid+1;
        else
            right = mid-1;
    }
    return 0;
}

int main()
{
    //freopen("data.txt","r",stdin);

    int len = 0;

    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    tmp = arr[k-1];

    for(int i=0; i<k-1; i++)
    {
        if(arr[i] < tmp)
            newarr[len ++] = arr[i];
    }
    newarr[len ++] = tmp;
    for(int i=k; i<n; i++)
    {
        if(arr[i] > tmp)
            newarr[len ++] = arr[i];
    }

    int i,j;

    d[1] = newarr[0];
    int lislen = 1;        //递增子序列长度
    for(i = 1; i <= n; i++)
    {
        if(d[lislen]<newarr[i])
        {
            lislen ++;
            j = lislen;
        }
        else
        {
            j = binarySearch(newarr[i],1,lislen) + 1;
        }
        d[j] = newarr[i];
    }

    cout<<lislen<<endl;
    return 0;
}
