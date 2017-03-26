#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 1000

typedef struct Point{
	int row;
	int col;
	struct Point *pre;
}Node;

int map[N][N],vis[N][N];/*map:迷宫  vis:是否访问*/
Node sol[N*N];
int map_row,map_col,new_row,new_col;
int i,j,p,top;
int dir_row[8]={-1,-1,-1, 0, 0, 1, 1, 1};/*搜索方向*/
int dir_col[8]={-1, 0, 1,-1, 1,-1, 0, 1};

void push(int p_row,int p_col){
	top++;
	sol[top].row=p_row;
	sol[top].col=p_col;
	sol[top].pre=&sol[p];
	return ;
}

int main(){
	
	scanf("%d%d",&map_row,&map_col);
	//init
	memset(vis,0,sizeof(vis));//0:未访问
	for(i=0;i<=map_col+1;i++)map[0][i]=map[map_row+1][i]=1;//设置地图边界
	for(i=0;i<=map_row+1;i++)map[i][0]=map[i][map_col+1]=1;
	sol[0].row=1;//初始化栈
	sol[0].col=1;
	sol[0].pre=NULL;
	vis[1][1]=1;
	//读取迷宫地图
	for(i=1;i<=map_row;i++)
		for(j=1;j<=map_col;j++)
			scanf("%d",&map[i][j]);
	//bfs
	p=0;top=0;
	while((sol[top].row!=map_row)||(sol[top].col!=map_col)){
		for(i=0;i<8;i++){
			new_row=sol[p].row+dir_row[i];
			new_col=sol[p].col+dir_col[i];
			if(map[new_row][new_col]==0)//路可以走
				if(vis[new_row][new_col]==0){//路没有走过
					push(new_row,new_col);
					vis[new_row][new_col]=1;
			}
		}
		p++;
	}

	//outupt
	Node *p1 = &sol[top];
	while(p1->pre!=NULL){
		printf("(%d,%d)\n",p1->row,p1->col);
		p1=p1->pre;
	}
	printf("(1,1)\n");

	return 0;
}
