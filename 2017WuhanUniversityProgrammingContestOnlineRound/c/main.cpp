#include <bits/stdc++.h>
using namespace std;
const int NN = 100000 + 100;

char arr[NN];
int dp[NN][6];

int main()
{
    int tmp;
    int Max = -1;
    scanf("%s",arr);
    int p = 0;
    memset(dp, 0x0, sizeof(dp));
    while(arr[p] == '0')p ++;
    dp[p][(arr[p]-'0')%6] = 1;
    int n = strlen(arr);
    for(int i=p+1;i<n;i++)
    {
        for(int j=0; j<6; j++)
        {
            tmp = arr[i]-'0';
            if(dp[i-1][j]!=0)
            {
                tmp += j*10;
            }
            if(dp[i-1][j] + 1>dp[i][tmp%6])
            dp[i][tmp % 6] = dp[i-1][j]+1;
        }
    }
    for(int i=p;i<n;i++)
        if(Max<dp[i][0])Max = dp[i][0];
    cout << Max << endl;
    return 0;
}
