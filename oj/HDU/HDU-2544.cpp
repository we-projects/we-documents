/*************************************************************************
    > File Name: hdu-2544.cpp
    > Author: sunowsir
    > GitHub: https://github.com/sunowsir/pratice
    > Created Time: 2017年08月12日 星期六 13时59分47秒
 ************************************************************************/

//最短路问题

#include<bits/stdc++.h>
using namespace std;

#define cls(x,y) memset(x,y,sizeof(x))
const int INF = 0x3f3f3f;
const int maxn = 1e3+10;
int e[maxn][maxn],dis[maxn];
bool book[maxn];
int n,m;

void dijkstra(){
	int min,pos=0;
	//初始化dis为1到各个点的边的权值；
	for(int i=1;i<=n;i++)
		dis[i]=e[1][i];
	for(int i=1;i<n;i++){
		min=INF;
		for(int j=1;j<=n;j++)
			if(!book[j]&&min>dis[j]){
				pos=j;
				min=dis[j];
			}
		//标记该点，表示已经走过；
		book[pos]=true;
		//更新权值
		for(int j=1;j<=n;j++)
			if(!book[j] && dis[j]>dis[pos]+e[pos][j])
				dis[j]=dis[pos]+e[pos][j];
	}
	return;
}

int main(){
	while(cin>>n>>m && n && m){
		cls(e,INF);
		cls(book,false);
		book[1]=true;
		int x,y,z;
		for(int i=1;i<=m;i++){
			cin>>x>>y>>z;
			e[x][y]=e[y][x]=z;
		}
		dijkstra();
		cout<<dis[n]<<endl;
	}
	return 0;
}
