#include<iostream>
#include<cstring>

using namespace std;

const int INF=1<<30;

int main(){
	
	int vmax[1000],w[100],v[100];
	int n,s;
	int i,j;
	
	cin >> n >>s;
	for(i=1;i<=n;i++){
		cin >>w[i] >> v[i];
	}
	//w[0]=v[0]=0;
	
	memset(vmax,0,sizeof(vmax));
	//for(i=1;i<=n;i++)vmax[i]=-INF;
	
	for(i=1;i<=s;i++)
		for(j=1;j<=n;j++)
			if(i>=w[j])vmax[i]=max(vmax[i],vmax[i-w[j]]+v[j]);
			
	cout << vmax[s];
	return 0;
} 
