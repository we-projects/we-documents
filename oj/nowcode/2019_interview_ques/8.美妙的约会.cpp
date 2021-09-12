/*
	* File      : 8.美妙的约会.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Tue 24 Mar 2020 04:59:06 PM CST
*/

#include <vector>
#include <iostream>

int main() {
	int n, couple_num;
	std::cin >> n;
	couple_num = n / 2;

	std::vector<int> list(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> list[i];
		if (i > 0 && list[i] == list[i - 1]) couple_num--;
	}

	if (couple_num == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
	}

	return 0;
}
