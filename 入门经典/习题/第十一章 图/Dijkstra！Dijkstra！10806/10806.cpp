/***************
用Dijkstra求两次最小，和不一定最小
构造最小费用最大流

邻接表 未完成

****************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110;
const int INF = 0x3f3f3f3f;

struct Node{
    int to;     /*终点  的位置*/
    int cap;    /*容量*/
    int rev;    /*反向边的位置*/
    int cost;   /*费用*/
};

vector <Node> RN[N];
int d[N],fa[N];
int n,m;
int x,y,z;
int sum_cost;

/*重边情况不影响*/
void add_Node(int from,int to,int cap,int cost){
    RN[from].push_back((Node){to,cap,RN[to].size(),cost});
    RN[to].push_back((Node){from,0,RN[from].size()-1,cost*(-1)});
}

int bellman_ford(){

    memset(d,INF,sizeof(d));
    d[0] = 0;sum_cost = 0;
    Node &tmp;

    for(int k = 0; k < n-1; k ++)
        for(int i= 1; i <= n; i ++)
            for(int j = 0;j < RN[i].size();j++){
                int &f=RN[i][j];
                if( (d[RN[i][j].to] < d[i]+RN[i][j].cost) && (RN[i][j].cap > 0) ){
                    d[RN[i][j].to] = d[i]+RN[i][j].cost;
                    fa[RN[i][j].to] = i;
                }
            }

    if(d[n] < INF){
        /*更新费用流*/
        int i = n;fa[0] = -1;
        while(fa[i] != -1){
            tmp = RN[fa[i]][i];
            tmp.cap -= 1;
            RN[tmp.to][tmp.rev].cap += 1;

            sum_cost +=tmp.cost;
            i = fa[i];
        }
        return sum_cost;
    }
    return 0;
}

int cost(){

    int max_cost = 0;
    for(;;){
        int f = bellman_ford();
        if(f == 0)return max_cost;
        max_cost += f;
    }
}

int main(){
    cin >> n;
    while(n){
        cin >> m;
        for(int i = 0;i < m;i ++){

            scanf("%d%d%d",&x,&y,&z);
            add_Node(x,y,z,1);
        }
        add_Node(0,1,2,0);

        printf("%d\n",cost());
        cin >> n;
    }
    return 0;
}
