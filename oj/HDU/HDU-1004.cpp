/*************************************************************************
    > File Name: hdu1004.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月07日 星期五 19时07分03秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
map<string,int> a;

int main(){
	string s;
	int n;
	cin>>n;
	while(cin>>n&&n){
		for(int i=0;i<n;i++){
			cin>>s;
			a[s]++;
		}
		string Max;
		map<string,int>::iterator it;
		int max=0;
		for(it=a.begin();it!=a.end();++it){
			//不断的与下一个相比大的给Max；
			if(a[it->first]>max){
				max=a[it->first];
				Max=it->first;
			}
		}
		cout<<Max<<endl;
		a.clear();
	}
	return 0;
}
