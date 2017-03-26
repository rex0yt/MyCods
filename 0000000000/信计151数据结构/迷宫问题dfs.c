#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 1100

struct Node{
	int row;
	int col;
	int dir;/*搜索方向*/
};

struct Point{
	int row;
	int col;
};

int map[N][N],vis[N][N];/*map:迷宫*/
struct Node sol[N*N];
struct Point poi;
int map_row,map_col;
int i,j,top;
struct Point dir[4]={{1,0},{0,-1},{-1,0},{0,1}};/* 下 左 上 右*/

void push(int p_row,int p_col){
	top++;
	sol[top].row=p_row;
	sol[top].col=p_col;
	sol[top].dir=0;
	vis[p_row][p_col]=1;/*已访问标记*/
}

void pop(){
	top--;
	return ;
} 

int main() {
	/*init*/
	memset(vis,0,sizeof(vis));
	/*读取迷宫地图*/
	scanf("%d%d",&map_col,&map_row);
	for(i=0;i<map_row;i++)
		for(j=0;j<map_col;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==3){
				sol[0].row=i;
				sol[0].col=j;
				sol[0].dir=0;
				vis[i][j]=1; 
			}
		}
	/*dfs搜索路径*/
	top=0;
	while(map[sol[top].row][sol[top].col]!=4){
		switch(sol[top].dir){
			case 0:case 1:
				case 2:case 3:
				poi.row=sol[top].row+dir[sol[top].dir].row;
				poi.col=sol[top].col+dir[sol[top].dir].col;
				sol[top].dir++;
				if(map[poi.row][poi.col]!=1)
					if(vis[poi.row][poi.col]==0)
						push(poi.row,poi.col);
				break;
			case 4:
				pop();
				break;
		}
	}
	/*outupt*/
	for(i=0;i<=top;i++)
		printf("%d %d\n",sol[i].col,sol[i].row);
	
	return 0;
}
