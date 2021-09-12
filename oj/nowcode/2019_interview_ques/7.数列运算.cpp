/*
	* File      : 7.数列运算.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sun 22 Mar 2020 05:21:35 PM CST
*/

#include <cmath>
#include <iostream>

int get(int n, int k) {
	int ans = 0;

	for (int i = 0, bit_num = 0; k; i++, k /= 2) {
		bit_num = k % 2;
		ans += bit_num * std::pow(n, i);
	}

	return ans;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	std::cout << get(n, k) << std::endl;
	return 0;
}
