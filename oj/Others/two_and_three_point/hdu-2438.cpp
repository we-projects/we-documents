/*************************************************************************
    > File Name: hdu-2438.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年08月01日 星期二 14时33分17秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-6;
double x,y,l,d;

double C(double m){
	return l * cos(m) - (x*cos(m)-d) / sin(m);
}

int main(){
	while(cin>>x>>y>>l>>d){
		double lb=0,ub=pi/2.0;
		double mid,mmid;
		while(ub-lb>=eps){
			mid=lb+(ub-lb)/3;
			mmid=ub-(ub-lb)/3;
			if(C(mid)<=C(mmid))  lb=mid+eps;
			else  ub=mmid-eps;
		}
		if(C(lb)>y)  cout<<"no"<<endl;
		else  cout<<"yes"<<endl;
	}
	return 0;
}
