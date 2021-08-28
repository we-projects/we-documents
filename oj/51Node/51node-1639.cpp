/*************************************************************************
    > File Name: 51node-1639.cpp
    > Author: sunowsir
    > GitHub: github.com/sunowsir/practice 
    > Created Time: 2017年08月26日 星期六 16时54分29秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

//组合数学
//感谢
// http://blog.csdn.net/cai_nia/article/details/53505678

int main(){
	int n;
	double ans;
	ans=1.0;
	cin>>n;
	for(int i=2;i<=n;i++)
		ans=2.0*(i-1)/(2*i-1)*ans;
	if(n==1)  cout<<1<<endl;
	else  printf("%.6f\n",ans);
	return 0;
}
