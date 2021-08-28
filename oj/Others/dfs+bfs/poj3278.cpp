/*************************************************************************
    > File Name: poj3278.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年08月02日 星期三 09时40分28秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

#define cls(x,y) memset(x,y,sizeof(x))
const int maxn = 1e5+10;
int n,k;
int tim[maxn];
bool vis[maxn];

int bfs(){
	queue<int> q;
	q.push(n);
	cls(vis,false);
	int m,t;
	vis[n]=true;
	tim[n]=0;
	while(!q.empty()){
		m=q.front();
		q.pop();
		if(m==k)  return tim[m];
		t=m*2;
		if(t<=1e5&&t>0&&!vis[t]){
			vis[t]=true;
			tim[t]=tim[m]+1;
			q.push(t);
		}
		t=m+1;
		if(t<=1e5&&t>=0&&!vis[t]){
			vis[t]=true;
			tim[t]=tim[m]+1;
			q.push(t);
		}
		t=m-1;
		if(t<=1e5&&t>=0&&!vis[t]){
			vis[t]=true;
			tim[t]=tim[m]+1;
			q.push(t);
		}
	}
	return -1;
}

int main(){
	while(cin>>n>>k)
		cout<<bfs()<<endl;
	return 0;
}
