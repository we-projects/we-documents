/*************************************************************************
    > File Name: poj1298.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月07日 星期五 10时13分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1e5;

int main(){
	char s[maxn];
	while(gets(s)){
		if(s[3]=='O'){
			cout<<endl;
			break;
		}
		else if(s[0]=='S')  continue;
		else if(s[0]=='E')  continue;
		else{
			int l=strlen(s);
			for(int i=0;i<l;i++){
				if(s[i]>='A'&&s[i]<='Z'){
					if(s[i]=='A')  s[i]='V';
					else if(s[i]=='B')  s[i]='W';
					else if(s[i]=='C')  s[i]='X';
					else if(s[i]=='D')  s[i]='Y';
					else if(s[i]=='E')  s[i]='Z';
					else s[i]=s[i]-5;
				}
			}
			for(int i=0;i<l;i++)  cout<<s[i];
			cout<<endl;
		}
	}
	return 0;
}
