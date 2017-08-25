#include <stdio.h>
#define MaxN 30+5
using namespace std;

int arr[MaxN];
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    arr[1] = 1;
    for(int i=2; i<=30; i++)
        arr[i] = arr[i-1]*2;
    int cnt = 0;
    for(int i=m; i<=n; i++)
        cnt += arr[i];
    printf("%d\n",cnt);
    return 0;
}
