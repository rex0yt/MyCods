#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct node
{
    int lc,rc;
    int s;
} tree[101];
    //i-j相连的数量
    //i为节点留j条枝的最优值
int apple[101][101],f[101][101];
int  v[101];//访问标志
int n,q;

void dfs(int k){
    int i;
    v[k]=0;
    for (i=1;i<=n;i++)
        if (v[i] && apple[k][i]!=-1){//没有访问且与父亲相连
            if (tree[k].lc==0) tree[k].lc=i;
            else tree[k].rc=i;//任意的 这里谁左右没关系 其实只是为了建树
            tree[i].s=apple[k][i];//孩子继承父亲 为后面dp搜素做准备
            dfs(i);
        }
}

int dp_max(int t,int k){
    int i,ls,lt,rs;
    if (f[t][k]!=-1) return f[t][k];//因为是自底向上dp 前面的必定最优
    if (t==0 || k==0){//分的枝条已经没有或已经是叶子节点
        f[t][k]=0;
        return 0;
    }
    f[t][k]=0;
    for ( i=0;i<=k-1;i++){//枚举左右孩子各取多少枝条所达到的最优值。
        ls=dp_max(tree[t].lc,i);
        rs=dp_max(tree[t].rc,k-1-i);
        if (f[t][k]<ls+rs) f[t][k]=ls+rs;
    }
    f[t][k]+=tree[t].s;//返回时父亲也要算。
    return f[t][k];
}

int main(){

    cin >> n >> q;
    memset(apple,-1,sizeof(apple));
    int a,b,c;
    for (int i=2;i<=n;i++){
        cin >> a >> b >> c;
        apple[a][b]=c;apple[b][a]=c;
    }
    memset(v,true,sizeof(v));
    memset(tree,0,sizeof(tree));
    dfs(1);
    memset(f,-1,sizeof(f));
    int ans=dp_max(1,q+1);
    cout << ans;
    return 0;
}
