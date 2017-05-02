#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200 + 10;
const int maxint = 0xfffffff;

int imap[MAXN][MAXN];
int t, s, d;
int m, n;
int vis[MAXN],dis[MAXN];

void Dijkstra(int srcpnt)
{
    int Min, pnt;
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++)dis[i] = imap[srcpnt][i];
    vis[srcpnt] = 1;
    dis[srcpnt] = 0;
    for(int i=0; i<n; i++)
    {
        Min = maxint;
        for(int j=0; j<n; j++)
        {
            if(!vis[j] && Min>dis[j])
            {
                pnt = j;
                Min = dis[j];
            }
        }
        vis[pnt] = 1;
        for(int j=0; j<n; j++)
        {
            if(!vis[j])
                dis[j] = min(dis[pnt]+imap[pnt][j], dis[j]);
        }
    }
    return ;
}

int main()
{
    int x, y, z;
    while(cin >> n >> m)
    {
        memset(imap, 0x0, sizeof(imap));
        while(m --)
        {
            cin >> x >> y >> z;
            if(imap[x][y] == 0)
                imap[x][y] = imap[y][x] = z;
            else if(imap[x][y] > z)
                imap[x][y] = imap[y][x] = z;
        }
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
            {
                if(imap[i][j] == 0)
                    imap[i][j] = maxint;
                imap[i][i] = 0;
            }

        int qidian, zhongdian;
        cin >> qidian >> zhongdian;
        Dijkstra(qidian);
        if(dis[zhongdian]<maxint)
            cout << dis[zhongdian] << endl;
        else
            cout << -1 << endl;

    }
    return 0;
}
