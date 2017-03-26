#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int INF = 999999;

double g[1024][1024];
int x[1024],y[1024];
int t = 1,N,n;

double dis(int a,int b){
    double d = sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
    if(d > 10)return INF;
    return d;
}

int main(){
    cin >> N;
    while(t <= N){
/*init*/
        cin >> n;
        for(int i = 0; i < n;i ++)
            for(int j = 0; j < n; j ++){
                if(i == j)g[i][j] = 0;
                else g[i][j] = g[j][i] = INF;
        }
/*input*/
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
            for(int j = 0; j < i; j ++){
                g[i][j] = g[j][i] = dis(i,j);
            }
        }
/*Floyd*/
        for(int k = 0; k < n; k ++)
            for(int i = 0; i < n; i ++)
                for(int j = 0; j < n; j ++){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
/*search && output*/
        cout << "Case #" << t << ':' << endl;
        double vmax = 0;

        for(int i = 0;i < n; i ++)
            for(int j = 0; j < n; j++){
                vmax = max(vmax,g[i][j]);
            }

        if(vmax >= INF)cout << "Send Kurdy" <<endl;
            else printf("%.4f\n",vmax);
        cout << endl;
        t ++;
    }
    return 0;
}
