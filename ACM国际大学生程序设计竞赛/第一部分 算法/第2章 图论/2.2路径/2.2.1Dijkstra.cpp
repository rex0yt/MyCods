const int Maxn=1000;
int dis[Maxn],g[Maxn][Maxn],N;
bool v[Maxn];

void dijkstra(){
	for(int i=1;i<=N;++i)dis[i]=INF;
	dis[i]=0;
	memset(v,0,sizeof v);
	for(int i=1;i<=N;++i){
		int mark=-1,mindis=INF;
		for(int j=1;j<=N;++j)
			if(!v[j]&&dis[j]<mindis){
				mindis=dis[j];
				mark=j;
			}
		v[mark]=1;
		for(int j=1;j<=N;++j)if(!v[j])
			dis[j]=min(dis[j],dis[mark]+g[mark][j]);
	}
}
