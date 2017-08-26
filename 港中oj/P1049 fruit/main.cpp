#include <iostream>
#include <queue>
#include <stdio.h>

#define N 10000 //1<=n<=10000

using namespace std;

priority_queue <int, vector<int>, greater<int> >pq;
int n;
int arr[N];
int tmp;
int cnt;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",arr+i);
        pq.push(arr[i]);
    }
    cnt = 0;
    while(pq.size() >= 2)
    {
        tmp = 0;
        tmp += pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        cnt += tmp;
        pq.push(tmp);
    }
    printf("%d\n",cnt);
    return 0;
}
