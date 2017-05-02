#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
const int maxint = 0x0f0f0f0f;
int imap[MAXN][MAXN];
int path[MAXN][MAXN];
int B[MAXN];

int n;
void floyd()
{
    int tmp;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                tmp = imap[i][k] + imap[k][j] + B[k];
                if(tmp < imap[i][j])
                {
                    path[i][j] = path[i][k];
                    imap[i][j] = tmp;
                }
                else
                {
                    if(tmp==imap[i][j])
                        path[i][j] = min(path[i][j], path[i][k]);
                }
            }
        }
    }
    return ;
}
void outputpath(int mm, int nn)
{
    if(path[mm][nn] < maxint)
    {
        outputpath(mm, path[mm][nn]);
        outputpath(path[mm][nn],nn);
    }
    else cout<<mm<<"-->";
    return ;
}
int main()
{
    int mm, nn;
    while(cin >> n && n)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                cin >> imap[i][j];
                if(imap[i][j] == -1)imap[i][j] = maxint;
            }
        for(int i=1; i<=n; i++)
            cin >> B[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                path[i][j]=j;
        floyd();
        while((cin >> mm >> nn) && ((mm+1)||(nn+1)))
        {
            cout<<"From "<<mm<<" to " <<nn<<" :"<<endl;
            //cout<<"Path: ";outputpath(mm,nn);cout<<nn<<endl;
            cout <<"Path: "<<mm;
            int t=mm;
            while(t!=nn)
            {
                printf("-->%d",path[t][nn]);
                t=path[t][nn];
            }cout << endl;
            cout<<"Total cost : "<<imap[mm][nn]<<endl;
            cout<<endl;
        }
    }
    return 0;
}
