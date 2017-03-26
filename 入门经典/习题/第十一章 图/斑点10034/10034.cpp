#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 110;

struct po{
    float x;
    float y;
};

int p[N];
float w[N*N];
int u[N*N], v[N*N], r[N*N];
int num_edge, n, m;
po point[N];

int cmp(const int i,const int j){//间接排序函数
    return w[i]<w[j];
}

int find(int x){//并查集 查找
    return x == p[x] ? x : p[x] = find(p[x]);
}

float Kruskal(){
    float ans = 0;
    for(int i = 0; i < n; i ++)p[i] = i;
    for(int i = 0; i < num_edge; i ++)r[i] = i;

    sort(r,r+num_edge,cmp);
    for(int i = 0; i < num_edge; i ++){

        int e = r[i];
        int x = find(u[e]);
        int y = find(v[e]);

        if(x != y){ans += w[e];p[x] = y;}
    }
    return ans;
}

float dis(const po a,const po b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    int num_case;
    int i,j;

    cin >> num_case;
    while(num_case --){
        cin >> n;m = -1;

        for(i = 0; i < n; i++){
            scanf("%f%f",&point[i].x,&point[i].y);
            for(j = 0; j < i; j++){
                m += 1;
                u[m] = i;
                v[m] = j;
                w[m] = dis(point[i],point[j]);
            }
        }
        num_edge = m + 1;

        printf("%.2f\n",Kruskal());
        if(num_case)cout << endl;
    }
    return 0;
}
