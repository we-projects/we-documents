/*************************************************************************
    > File Name: hdu-1233.cpp
    > Author: sunowsir
    > *** *** 
    > Created Time: 2017年08月09日 星期三 15时16分03秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10;
const int INF = 0x3f3f3f;
int visited[maxn],low[maxn],mp[maxn][maxn];
int n;

int prim(){
	int pos,min,res=0;
	memset(visited,0,sizeof(visited));
	memset(low,INF,sizeof(low));
	visited[1]=1;
	pos=1;
	for(int i=1;i<=n;i++){
		if(i!=pos)
			low[i]=mp[pos][i];
	}
	for(int i=1;i<n;i++){
		min=INF;
		for(int j=1;j<=n;j++){
			if(visited[j]==0&&min>low[j]){
				min=low[j];
				pos=j;
			}
		}
		res+=min;
		visited[pos]=1;
		for(int j=1;j<=n;j++){
			if(visited[j]==0&&low[j]>mp[pos][j])
				low[j]=mp[pos][j];
		}
	}
	return res;
}

int main(){
	int a,b,c;
	while(cin>>n&&n!=0){
		memset(mp,INF,sizeof(mp));
		for(int i=0;i<(n*(n-1)/2);i++){
			cin>>a>>b>>c;
			mp[a][b]=c;
			mp[b][a]=c;
		}
		cout<<prim()<<endl;
	}
	return 0;
}
