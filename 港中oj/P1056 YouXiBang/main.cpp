#include <stdio.h>
#define MaxN 50+10

using namespace std;

int arr[MaxN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        arr[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        arr[i] += 6;
        arr[i] += i;
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
