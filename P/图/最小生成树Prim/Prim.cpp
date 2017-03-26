#include"Graph.h"
#define INFINITE INT_MAX
#include<iostream>
using namespace std;
int main(int argc,char **argv){
	int i,j,k,n;
 	cout<<"请输入定点数:";
 	cin>>n;
 	Graph *g=new Graph(n);
//建图
 	cout <<"请输入该无向图的下三角矩阵(-1表示无边相连):"<<endl;
 	for(i=0;i<n;i++){
  		for(j=0;j<=i;j++){
   			int tempInput;
   			cin>>tempInput;
   			if(tempInput==-1)tempInput=INFINITE;
   			g->setEdge(i,j,tempInput);
  		}
 	}
//动态建立数组u
 	int **u=new int*[n];
 	for(i=0;i<n;i++){
  		u[i]=new int[3];
  	//u数组初始化
  		u[i][0]=0;//存储与i相连的令一节点的标号j
  		u[i][1]=INFINITE;
  		u[i][2]=0;//0表示没选为u数组里面，否则为1
 	}	
 	u[0][2]=1;//从第一个开始选，第一个默认选入u里面
//开始搜索
 	cout<<endl<<"下面Prim的输出最小生成树:"<<endl;
 	int shortest=INFINITE;
 	int index[2]={0,0};
 	for(k=0;k<n;k++){
  		shortest=INFINITE;
  		index[0]=-1;
  		index[1]=-1;
  		for(i=0;i<n;i++){//找出与u中顶点相连的最小距离
   			if(u[i][2]==1){//另一顶点在u里面
    			for(j=0;j<n;j++){//找到与i的最小的边
     				if(u[j][2]==0&&g->getEdge(i,j)<INFINITE){//该顶点不在u里面并且该边存在
				       	if(u[i][1]>g->getEdge(i,j)){//该边的值小于当前最小值
				        	u[i][0]=j;
				        	u[i][1]=g->getEdge(i,j);
				       	}
				       	if(shortest>g->getEdge(i,j)){
					        shortest=g->getEdge(i,j);
					        index[0]=i;//记录当前最短的边的两顶点
					        index[1]=j;
				       	}
     				}
    			}
   			}
  		}
		if(index[0]>=0){
			u[index[1]][0]=index[0];
			u[index[1]][1]=shortest;
			u[index[1]][2]=1;
			cout<<"<"<<(char)('a'+index[0])<<">"<<"--"
				<<shortest<<"--"<<"<"<<(char)('a'+index[1])<<">"<<endl;
		}
 	}
 	cout<<endl<<"另外一种输出形式为:"<<endl;
 	for(i=0;i<n;i++){
  		cout<<"<"<<i+1<<">"<<"--"
		  	<<g->getEdge(i,u[i][0])<<"--"<<"<"<<u[i][0]+1<<">"<<endl;
 	}
 	return 0;
}
