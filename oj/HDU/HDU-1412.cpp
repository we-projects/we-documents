/*************************************************************************
    > File Name: hdu1412.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月07日 星期五 17时13分14秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

set<int> st;

int main(){
	int a,b,num;
	while(cin>>a>>b){
		st.clear();
		for(int i=0;i<a;i++){
			cin>>num;
			st.insert(num);
		}
		for(int i=0;i<b;i++){
			cin>>num;
			st.insert(num);
		}
		int tmp=0;
		set<int>::iterator it=st.begin();
		for(;it!=st.end();it++){
			if(tmp==1)  cout<<" ";
			cout<<*it;
			tmp=1;
		}
		cout<<endl;
	}
	return 0;
}
