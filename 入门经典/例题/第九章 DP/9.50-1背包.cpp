#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int v[100],w[100],d[100][1000];
	int c,n,i,j;
	
	cin >> c >> n;
	for(i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
		
	memset(d,0,sizeof(d));
	
	for(i = n; i >= 1; i --)
		for(j = 0; j <= c; j ++){
			d[i][j] = (i==n ? 0 : d[i+1][j]);
			if(j >= v[i])d[i][j]=max(d[i][j],d[i+1][j-v[i]]+w[i]);
		}
	
	cout << d[1][c] << endl;
	
	return 0;
}
