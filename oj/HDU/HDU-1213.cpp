/*************************************************************************
    > File Name: hdu-1213.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2017年08月09日 星期三 08时48分32秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;

struct Node{
	int par,rank;
};

Node node[maxn];
bool book[maxn];

//初始化；
void init(int n){
	for(int i=0;i<n;i++){
		node[i].par=i;
		node[i].rank=0;
	}
	memset(book,false,sizeof(book));
}

//查找x的根；
int find(int x){
	if(node[x].par==x)  return x;
	else  return node[x].par=find(node[x].par);
}

//合并x和y所归属的树；
void unite(int x,int y){
	//找到x和y的根；
	x=find(x);
	y=find(y);
	//x==y:说明传入的x和y是一个根，归属一个树；
	if(x==y)  return;
	//根据两个树的高度来决定谁放在谁的下面；
	//如果两个树的高度不相等，高度小的树的根放在大的根下面成为儿子，所以高度不用变化；
	if(node[x].rank<node[y].rank)  node[x].par=y;
	else{
		node[y].par=x;
		//由于上面已经把y连接到x上成为x的儿子，所以如果两个树高度相等，x树的高度增加1；
		if(node[x].rank==node[y].rank)  node[x].rank++;
	}
}

int main(){
	int t,n,m,x,y,ans,tmp;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			x--,y--;
			unite(x,y);
		}
		ans=0;
		for(int i=0;i<n;i++){
			tmp=find(i);//有几个根，就有几个集合；
			if(!book[tmp]){
				book[tmp]=true;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
