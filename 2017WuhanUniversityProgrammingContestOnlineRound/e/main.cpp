#include <iostream>
#include <queue>

using namespace std;

const int NN = 100 + 5;
const int modd  = 1e9 + 7;
const int maxint = 0x7fffffff;
int dist[NN];
int pprev[NN];

struct node
{
    int no;
    int cengshu;
};

int n, m;
int imap[NN][NN];
queue <node> iqueue;
long long ans = 0;
int cet;

void intial()
{
    node tmp;
    tmp.no = 1;
    tmp.cengshu = 0;
    iqueue.push(tmp);
    return ;
}
void sol()
{
    node tmp = iqueue.front();
    node newone;
    while(tmp.cengshu <= cet)
    {
        if(tmp.no == n)
        {
            ans ++;
            ans %= modd;
        }
        else
        {
            for(int i = 1; i <= n; i ++)
            {
                if(tmp.no == i)continue;
                if(imap[tmp.no][i] != maxint)
                {
                    if(dist[i] < cet)
                    {
                        newone.no = i;
                        newone.cengshu = tmp.cengshu + 1;
                        iqueue.push(newone);
                    }
                }
            }
        }
        iqueue.pop();
        tmp = iqueue.front();
    }
}
void Dijkstra(int n,int v)
{
    bool s[NN];
    for(int i=1; i<=n; ++i)
    {
        dist[i]=imap[v][i];
        s[i]=0;
        if(dist[i]==maxint)pprev[i]=0;
        else pprev[i]=v;
    }
    dist[v]=0;
    s[v]=1;
    for(int i=2; i<=n; ++i)
    {
        int tmp=maxint;
        int u=v;
        for(int j=1; j<=n; ++j)
            if((!s[j])&&dist[j]<tmp)
            {
                u=j;
                tmp=dist[j];
            }
        s[u]=1;
        for(int j=1; j<=n; ++j)
            if((!s[j])&&imap[u][j] < maxint)
            {
                int newdist = dist[u]+imap[u][j];
                if(newdist<dist[j])
                {
                    dist[j]=newdist;
                    pprev[j]=u;
                }
            }
    }
}

void dj()
{
    for(int i=1; i<=n; ++i)
        dist[i]=maxint;
    Dijkstra(n, n);
}

int main()
{
    int x, y;

    for(int i = 0;i < NN;i ++)
        for(int j = 0;j < NN ; j++)
            imap[i][j] = maxint;

    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> x >> y;
        imap[y][x] = imap[x][y] = 1;
    }
    cin >> cet;

    dj();
    intial();
    sol();

    cout << ans << endl;

    return 0;
}
