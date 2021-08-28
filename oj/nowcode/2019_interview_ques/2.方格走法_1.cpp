/*
	* File      : 2.方格走法_1.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sat 21 Mar 2020 07:30:25 PM CST
*/

#include <iostream>
#include <vector>

#define ll long long 
#define X 13
#define Y 13
std::vector<std::vector<ll>> dp(X , std::vector<ll>(Y , 0));

void draw() {
	dp[1][2] = 1;
	dp[2][1] = 1;

	for (ll i = 1; i < X; i++) {
		for (ll j = 1; j < Y; j++) {
			if (i + j > 3) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	// for (ll i = 1; i < X; i++) {
	// 	for (ll j = 1; j < Y; j++) {
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

}

int main() {
	draw();
	int x, y;
	std::cin >> x >> y;
	std::cout << dp[x + 1][y + 1] << std::endl;
	return 0;
}

#undef ll
