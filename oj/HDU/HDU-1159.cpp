/*************************************************************************
    > File Name: hdu-1159.cpp
    > Author: sunowsir
    > GitHub: https://github.com/sunowsir/pratice
    > Created Time: 2017年08月12日 星期六 15时12分08秒
 ************************************************************************/

//最长公共子序列

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1001;
char s[maxn], t[maxn];
int dp[maxn][maxn];

void lcs() {
	int n = strlen(s);
	int m = strlen(t);
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
			}
		}
	}
	printf("%d\n", dp[n][m]);
}

int main() {
	while (cin>>s>>t) {
		lcs();
	}
	return 0;
}
