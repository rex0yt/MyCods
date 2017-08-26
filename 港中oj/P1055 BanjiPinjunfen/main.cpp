#include <iostream>
#include <stdio.h>

#define N 100+10

using namespace std;

int main()
{
    int n;
    float arr[N];
    float avg;


    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        avg += arr[i];
    }
    avg /= n;

    for(int i=0; i<n; i++)
    {
        printf("%d:%.1f\n",i+1,arr[i]);
    }
    printf("%.2f\n",avg);
    return 0;
}
