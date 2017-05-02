#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 200;
const int maxint  = 0xfffffff;

int imap[MAXN][MAXN];
int t, s, d;
int n;
int vis[MAXN],dis[MAXN];

int* Dijkstra(int srcpnt)
{
    int Min, pnt;
    for(int i=0; i<=n; i++)
        dis[i] = imap[srcpnt][i];
    memset(vis, 0x0, sizeof(vis));
    dis[srcpnt] = 0;
    vis[srcpnt] = 1;
    for(int i=0; i<n; i++)
    {
        Min = maxint;
        for(int j=1; j<=n; j++)
            if(!vis[j] && Min > dis[j])
            {
                pnt = j;
                Min = dis[j];
            }
        vis[pnt] = 1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j])
                dis[j] = min(dis[j], Min + imap[pnt][j]);
        }
    }
    return dis;
}

int main()
{
    int x, y, z;
    int Min;
    while(cin >> t >> s >> d)
    {
        memset(imap, 0x0, sizeof(imap));
        n = 0;
        while(t --)
        {
            cin >> x >> y >> z;
            if(imap[x][y] == 0)
                imap[x][y] = imap[y][x] = z;
            else if(imap[x][y] > z)
                imap[x][y] = imap[y][x] = z;
            n=max(x,max(y,n));
        }
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
            {
                if(imap[i][j] == 0)
                    imap[i][j] = maxint;
                imap[i][i] = 0;
            }

        Min = maxint;
        int arr[MAXN];
        for(int i=0; i<s; i++)
        {
            cin >> x;
            imap[x][0] = imap[0][x] = 0;
        }
        for(int i=0; i<d; i++)cin >> arr[i];
        int *a = Dijkstra(0);
        for(int j=0; j<d; j++)
            Min = min(Min, a[arr[j]]);
        cout << Min << endl;
    }
    return 0;
}
