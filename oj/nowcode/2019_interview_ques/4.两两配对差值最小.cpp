/*
	* File      : 4.两两配对差值最小.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sat 21 Mar 2020 08:48:07 PM CST
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, max, min;
	max = 0;
	min = 201;
	std::cin >> n;

	std::vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::sort(arr.begin(), arr.end());

	for (int i = 0; i < (n >> 1); i++) {
		int new_num = arr[i] + arr[n - i - 1];
		min = std::min(min, new_num);
		max = std::max(max, new_num);
		// std::cout << arr[i] << " + " << arr[n - i - 1] << " = " << new_num << std::endl;
	}

	// std::cout << std::endl;
	// std::cout << "max = " << max << std::endl;
	// std::cout << "min = " << min << std::endl;
	std::cout << (max - min) << std::endl;

	return 0;
}
