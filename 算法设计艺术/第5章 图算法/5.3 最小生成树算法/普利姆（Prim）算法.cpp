void Prim(int n,int u0,int C[n][n]){//顶点个数n,开始顶点u0,带权邻接矩阵C[n][n] 
//如果s[i]=ture,说明顶点i已加入最小生成树的顶点集合U;否则顶点i属于集合V-U
	bool s[n];
	int closest[n];
	double lowcost[n];
	s[u0]=1;					//初始时,集合U中只有一个元素 
	for(int i=0;i<n;i++){
		if(i!=u0){
			lowcost[i]=C[u0][i];
			closest[i]=u0;
			s[i]=false;
		}
	}
	for(int i=0;i<n;i++){			//在集合V-U中寻找距离集合U最近的顶点并更新 
								//lowcost和closest 
		double temp=INF;		//temp初始化为无穷大 
		int t=u0;
		for(int j=0;j<n;i++){	//在集合V-U中寻找距离集合U最近的顶点t 
			if((!s[j])&&(lowcost[j]<temp)){
				t=j;
				temp=lowcost[j];
			}
		}
		if(t==u0)
			break;				//找不到t,跳出循环 
		s[t]=true;				//否则,将t加入集合U 
		for(j=0;j<n;j++){		//更新lowcost和closest 
			if((!s[j])&&(C[t][j]<lowcost[j])){
				lowcost[j]=C[t][j];
				closest[j]=t;
			}
		} 
	}
}
