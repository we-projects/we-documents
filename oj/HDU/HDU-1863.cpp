/*************************************************************************
    > File Name: hdu-1863.cpp
    > Author: sunowsir
    > *** *** 
    > Created Time: 2017年08月09日 星期三 15时57分22秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define cls(x,y) memset(x,y,sizeof(x))
const int maxn = 1e3+10;
const int INF = 0x3f3f3f;
int mp[maxn][maxn],visited[maxn],low[maxn];
int n,m;//n个村庄

void prim(){
	int res,pos,min;
	res=0;
	cls(visited,0);
	cls(low,INF);
	visited[1]=1;
	pos=1;
	for(int i=2;i<=n;i++)  low[i]=mp[1][i];
	for(int i=1;i<n;i++){
		min=INF;
		for(int j=1;j<=n;j++){
			if(visited[j]==0&&min>low[j]){
				min=low[j];
				pos=j;
			}
		}
		if(min==INF){
			cout<<"?"<<endl;
			return;
		}
		res+=min;
		visited[pos]=1;
		for(int j=1;j<=n;j++){
			if(visited[j]==0&&low[j]>mp[pos][j])
				low[j]=mp[pos][j];
		}
	}
	cout<<res<<endl;
	return;
}

int main(){
	int a,b,c;
	while(cin>>m>>n&&m!=0){
		cls(mp,INF);
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			mp[a][b]=c;
			mp[b][a]=c;
		}
		prim();
	}
}
