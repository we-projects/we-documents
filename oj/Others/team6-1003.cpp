/*************************************************************************
    > File Name: team6-1003.cpp
    > Author: sunowsir
    > *** *** 
    > Created Time: 2017年08月10日 星期四 15时21分24秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
#define cls(x,y,sizeof(x))

struct Node{
	int id,num;
};

Node a[maxn];

bool cmp(Node x,Node y){
	return x.num>y.num;
}

int main(){
	int t,n,tmp,ans;
	scanf("%d",&t);
	while(t--){
		cls(a.num,0);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			a[i].id=i+1;
			a[i].num=tmp;
		}
		tmp=0;
		sort(a,a+n,cmp);
		for(int i=2;i<=n;i++){
			for(int j=0;j<n;j++){
				if(a[j].id % i != 0){
					ans = a[j].num;
					break;
				}
			}
			if(tmp==1)  printf(" ");
			tmp=1;
			printf("%d",ans);
		}
		printf("\n");
	}
	return 0;
}
