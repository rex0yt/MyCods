#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF=50;

int num,x,y,t;
int d[25][25];

int main()
{
    t=0;
    while(cin>>num){
/*init*/
        for(int i=1;i<=20;i++)
            for(int j=1;j<=20;j++){
                if(i==j)d[i][j]=0;
                else d[i][j]=INF;
            }
/*input*/
        for(int i=1;i<=19;i++){
            if(i!=1)cin>>num;
            for(int j=1;j<=num;j++){
               cin>>x;
               d[i][x]=d[x][i]=1;
            }
        }
/*Floyd*/
        for(int k=1;k<=20;k++)
            for(int i=1;i<=20;i++)
                for(int j=1;j<=20;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
/*output*/
        t++;
        cout<<"Test Set #"<<t<<endl;
        cin>>num;
        for(int i=1;i<=num;i++){
            cin>>x>>y;
            printf("%2d to %2d: %d\n",x,y,d[x][y]);
        }
        cout<<endl;
    }

    return 0;
}
