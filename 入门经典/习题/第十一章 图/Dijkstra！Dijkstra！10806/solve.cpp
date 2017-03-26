#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=102;
const int inf=2<<20;
int cost[maxn][maxn],flow[maxn][maxn],cap[maxn][maxn],d[maxn];
int n,m;
int solve()
{
    queue<int> q;
    int i,vis[maxn],p[maxn],tot=0;
    while(1)
    {
        for(i=1;i<=n+1;i++)
        {
            d[i]=i==1?0:inf;
            vis[i]=0;
        }
        q.push(1);
        int x;
        while(!q.empty())
        {
            x=q.front();
            q.pop();
            vis[x]=0;
            for(i=1;i<=n+1;i++)
            {
                if(cap[x][i]>flow[x][i]&&d[i]>d[x]+cost[x][i])
                {
                    d[i]=d[x]+cost[x][i];
                    p[i]=x;
                    if(!vis[i])
                    {
                        vis[i]=1;
                        q.push(i);
                    }
                }
            }
        }
        if(d[n+1]==inf) break;
        int min=inf;
        for(i=n+1;i!=1;i=p[i])
        {
            if(min>(cap[p[i]][i])-flow[p[i]][i])
                min=cap[p[i]][i]-flow[p[i]][i];
        }
        for(i=n+1;i!=1;i=p[i])
        {
            flow[p[i]][i]+=min;
            flow[i][p[i]]-=min;cost[i][p[i]]=-cost[i][p[i]];
        }
        tot+=min*d[n+1];
        if(flow[n][n+1]==2) return tot;
    }
    return -1;
}
int main()
{
    while(cin>>n&&n!=0)
    {
        cin>>m;
        int i;
        int tu,tv,tw;
        memset(flow,0,sizeof(flow));
        memset(cost,inf,sizeof(cost));
        memset(cap,0,sizeof(cap));
        for(i=1;i<=m;i++)
        {
            cin>>tu>>tv>>tw;
            cost[tu][tv]=tw;cap[tu][tv]=1;
            cost[tv][tu]=tw;cap[tv][tu]=1;
        }
        cap[n][n+1]=2;cost[n][n+1]=cost[n+1][n]=0;
        int ou=solve();
        if(ou!=-1) cout<<ou<<endl;
        else cout<<"Back to jail"<<endl;
    }
    return 0;
}
