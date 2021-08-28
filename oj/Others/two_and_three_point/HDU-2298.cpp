/*************************************************************************
    > File Name: HDU-2298.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年08月01日 星期二 12时35分06秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1);
const double eps = 1e-10;
const double G = 9.8;

int T;
double x,y,v;

double C(double m){
	double vx=v*cos(m);
	double vy=v*sin(m);
	return (vy*x)/vx-G*(x/vx*x/vx)/2.0;
}

bool B(double m){
	double vx=v*cos(m);
	double vy=v*sin(m);
	return (vy*x)/vx-G*(x/vx*x/vx)/2.0>=y;
}

int main(){
	cin>>T;
	while(T--){
		cin>>x>>y>>v;
		double lb=0,ub=pi/2.0;
		//首先找出最大高度
		while(ub-lb>eps){
			double mid=(lb+ub)/2.0;
			double mmid=(mid+ub)/2.0;
			if(C(mid)>C(mmid))  ub=mmid;
			else  lb=mid;
		}
		if(C(ub)<y){
			cout<<"-1"<<endl;
			continue;
		}
		//然后从最大高度逐渐逼近目标物体的高度
		lb=0;
		while(ub-lb>eps){
			double mid=(ub+lb)/2.0;
			if(B(mid)){
				ub=mid;
			}
			else  lb=mid;
		}
		printf("%.6lf\n",ub);
	}
	return 0;
}
