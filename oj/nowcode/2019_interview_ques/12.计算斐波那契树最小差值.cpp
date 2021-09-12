/*
	* File      : 12.计算斐波那契树最小差值.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sat 28 Mar 2020 03:37:24 PM CST
*/

#include <iostream>

int get(int n) {
	if (n <= 3) return 0;
	int first = 5;
	int second = 8;

	while (second < n) {
		int temp = second;
		second += first;
		first = temp;
	}
	return ((abs(second - n) < abs(first - n) ? abs(second - n) : abs(first - n)));
}

int main() {
	int n;
	std::cin >> n;
	std::cout << get(n) << std::endl;
	return 0;
}
