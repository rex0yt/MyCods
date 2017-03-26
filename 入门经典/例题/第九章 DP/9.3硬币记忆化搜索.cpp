#include <iostream>
#include <cstring>

using namespace std;

const int vmin=-1<<30,vmax=1<<30;

int v[100],vis[10000],d[10000];
int n,s;

int dp(int s1){
	if(vis[s1])return d[s1];
	
	vis[s1]=1;d[s1]=vmin;
	for(int i0=1;i0<=n;i0++)if(s1>=v[i0])d[s1]=max(d[s1],dp(s1-v[i0])+1);
	
	return d[s1];
}
int main(int argc, char** argv) {
	
	/*input*/
	cin >> n >> s;
	for(int i=1;i<=n;i++)cin >> v[i];
	
	/*clear*/
	memset(vis,0,sizeof(vis));vis[0]=1;
	memset(d,-1,sizeof(d));d[0]=0;
	
	/*output*/
	cout << dp(s)<<endl;
	
	return 0;
}
