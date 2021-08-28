/*************************************************************************
    > File Name: 7-29-g.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月29日 星期六 14时44分17秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e6+10;

int main(){
	int n,cow[maxn];
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>cow[i];
		}
		sort(cow,cow+n);
		cout<<cow[n/2]<<endl;
	}
	return 0;
}
