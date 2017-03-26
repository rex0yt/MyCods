//定义图类 
class Graph{
public:
	Graph(){}
	Graph(int n){
		matrix=new int*[n];
		for(int i=0;i<n;i++){
			matrix[i]=new int[i+1];
		}
	}
 	void setEdge(int i,int j,int val);
 	int getEdge(int i,int j);
private:
	int **matrix;
};
void Graph::setEdge(int i,int j,int val){
 	int temp;
 	if(i<j){temp=i;i=j;j=temp;}//交换i和j的值
 	matrix[i][j]=val;
}
int Graph::getEdge(int i,int j){
 	int temp;
 	if(i<j){temp=i;i=j;j=temp;}//交换i和j的值 
 	return matrix[i][j];
}
