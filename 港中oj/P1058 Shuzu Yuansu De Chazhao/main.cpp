#include <stdio.h>
#define MaxN 100+10
using namespace std;

int arr[MaxN];

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",arr+i);

    int m;
    scanf("%d",&m);
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == m)break;
    }
    if(i<n)printf("%d\n",i+1);
    else printf("-1\n");
    return 0;
}
