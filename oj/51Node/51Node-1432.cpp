/*************************************************************************
    > File Name: 51node1432.cpp
    > Author: sunowsir
    > GitHub: github.com/sunowsir/practice 
    > Created Time: 2017年08月26日 星期六 14时02分44秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

//贪心

#define cls(x,y) memset(x,y,sizeof(x))
const int maxn = 1e5+10;
int weight[maxn];
int n,m,ans;
int x,y;

int solve(int x,int y){
	if(y<x)  return ans;
	ans++;
	if(x==y)  return ans;
	if(weight[x]+weight[y]<=m){
		x++;
		y--;
		solve(x,y);
	}
	else{
		y--;
		solve(x,y);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	ans=0;
	x=0;y=n-1;
	cls(weight,0);
	for(int i=0;i<n;i++)
		scanf("%d",&weight[i]);
	sort(weight,weight+n);
	cout<<solve(x,y)<<endl;
	return 0;
}
