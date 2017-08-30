#include <iostream>
#include <stdio.h>

#define M 100+10
#define T 1000+100

using namespace std;

int sol[M][T];
int t, m;
int medic_value[M],medic_time[M];

int main()
{
    //freopen("data.txt", "r",stdin);

    cin >> t >> m;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&medic_time[i],&medic_value[i]);
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<=t; j++)
        {
            sol[i][j] = sol[i-1][j];
            if(j >= medic_time[i])
                sol[i][j] = max(sol[i][j], sol[i-1][j-medic_time[i]] + medic_value[i]);
        }
    }
    cout << sol[m][t] << endl;
    return 0;
}
