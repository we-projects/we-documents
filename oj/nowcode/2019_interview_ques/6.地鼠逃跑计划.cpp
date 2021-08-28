/*
	* File      : 6.地鼠逃跑计划.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sun 22 Mar 2020 03:14:57 PM CST
*/

#include <iostream>

int DFS(int m, int n, int x, int y, int k) {
	// if (k <= 0) return (x < 0 || x >= m || y < 0 || y >= n);
	if (x < 0 || x >= m || y < 0 || y >= n) {
		// std::cout << "x = " << x << ", y = " << y << std::endl;
		return (k >= 0);
	}
	if (k <= 0) return (x < 0 || x >= m || y < 0 || y >= n);

	int ans = 0;
	ans += DFS(m, n, x - 1, y, k - 1);
	ans += DFS(m, n, x + 1, y, k - 1);
	ans += DFS(m, n, x, y - 1, k - 1);
	ans += DFS(m, n, x, y + 1, k - 1);

	return ans;
}

int main() {
	int m, n, x, y, k;
	std::cin >> m >> n >> x >> y >> k;
	std::cout << DFS(m, n, x, y, k) << std::endl;
	return 0;
}
