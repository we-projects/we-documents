/*************************************************************************
    > File Name: hdu1166.cpp
    > Author: sunowsir
    > GitHub: https://github.com/sunowsir/pratice
    > Created Time: 2017年08月12日 星期六 13时08分04秒
 ************************************************************************/

//树状数组

#include<bits/stdc++.h>
using namespace std;

#define cls(x,y) memset(x,y,sizeof(x))
const int maxn = 5e4+10;
int bit[maxn];
int n;

//求前i项的和。
int sum(int i){
	int s=0;
	while(i>0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

//把编号为i的数x添加到二叉树bit中
void add(int i,int x){
	while(i<=n){
		bit[i] += x;
		i += i & -i;
	}
}

int main(){
	int t,N,tmp;
	N=1;
	cin>>t;
	while(t--){
		//初始化
		cls(bit,0);
		//n个数
		cin>>n;
		for(int i=1;i<=n;i++){
			//输入
			cin>>tmp;
			//用add函数把第i个数tmp添加到在树上。
			add(i,tmp);
		}
		//输入命令（见题目）
		string str;
		int i,j;
		printf("Case %d:\n",N++);
		while(cin>>str && str!="End"){
			//输入命令后面的数，（不懂见题目）
			cin>>i>>j;
			//根据题意，把第i个数增加j，用add函数就能够实现
			if(str == "Add")  add(i,j);
			//把第i个数减少j，其实就是把第i个数增加-j，用add函数实现。
			else if(str == "Sub")  add(i,-j);
			//求区间i到j的和，用钱j项的和减去前i-1项的和。
			else  cout<<sum(j)-sum(i-1)<<endl;
		}
	}
	return 0;
}
