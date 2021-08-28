/*************************************************************************
    > File Name: 7-29-a.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月29日 星期六 14时14分26秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 150+10;

struct node{
	int begin;
	int end;
};
node ti[maxn];

bool cmp(node a,node b){
	if(a.end == b.end)  return a.begin<b.begin;
	else  return a.end<b.end;
}

int main(){
	int n;
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			cin>>ti[i].begin>>ti[i].end;
		}
		sort(ti,ti+n,cmp);
		int ans=1;
		int k=0;
		for(int i=1;i<n;i++){
			if(ti[i].begin>=ti[k].end){
				ans++;
				k=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
