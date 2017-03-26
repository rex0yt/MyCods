#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct{
    int lc,rc;
    int s;
} tree[101];

int apple[101][101],f[101][101];
int v[101];
int n,q;
int i;

void dfs(int k){

    v[k]=0;
    for(i=1;i<=n;i++)
        if (v[i] && apple[k][i]!=-1){
            if(tree[k].lc==0) tree[k].lc=i;
                else tree[k].rc=i;
            tree[i].s=apple[k][i];
            dfs(i);
        }
}

int dp_max(int t,int k){

    int i,ls,rs;
    if(f[t][k]!=-1) return f[t][k];
    if(t==0 || k==0){
        f[t][k]=0;return 0;
    }
    f[t][k]=0;
    for(i=0;i<=k-1;i++){
        ls=dp_max(tree[t].lc,i);
        rs=dp_max(tree[t].rc,k-1-i);
        if (f[t][k]<ls+rs) f[t][k]=ls+rs;
    }
    f[t][k]+=tree[t].s;

    return f[t][k];
}
int main(){

    int a,b,c;
    int ans;

    cin >> n >> q;
    memset(apple,-1,sizeof(apple));
    for(i=2;i<=n;i++){
        cin >> a >> b >> c;
        apple[a][b]=c;apple[b][a]=c;
    }
    memset(v,1,sizeof(v));
    memset(tree,0,sizeof(tree));
    dfs(1);
    memset(f,-1,sizeof(f));
    ans=dp_max(1,q+1);
    cout << ans;
    return 0;
}
