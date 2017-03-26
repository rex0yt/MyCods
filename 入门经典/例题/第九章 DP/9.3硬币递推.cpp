#include<iostream>

using namespace std;

const int INF=1<<30;

int main(){
	
	int vmin[1000],vmax[1000],v[100];
	int n,s;
	
	cin >> n >>s;
	for(int i=1;i<=n;i++){
		cin >>v[i];
	}
	
	vmin[0]=vmax[0]=0;
	for(int i=1;i<=s;i++){
		vmin[i]=INF;vmax[i]=-INF;
	}
	
	for(int i=1;i<=s;i++){
		for(int j=1;j<=n;j++){
			if(i>=v[j]){
				vmin[i]=min(vmin[i],vmin[i-v[j]]+1);
				vmax[i]=max(vmax[i],vmax[i-v[j]]+1);
			}
		}
	}
	
	cout << vmax[s] << ' ' << vmin[s];
	return 0;
} 
