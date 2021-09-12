/*
	* File      : 5.分玩具.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sun 22 Mar 2020 02:29:54 PM CST
*/

#include <iostream>
#include <vector>

bool judge(int a, int b) {
	return (std::abs(a - b) % 2);
}

int main() {
	int m, ave;
	ave = 0;
	std::cin >> m;
	std::vector<int> arr(m, 0); 

	for (int i = 0; i < m; i++) {
		std::cin >> arr[i];
		ave += arr[i];
	}

	int ans = 0;
	ave /= arr.size();

	for (int i = 0; i < m; i++) {
		if (ans == -1) break;
		if (arr[i] < ave) {
			if (judge(ave, arr[i])) {
				ans = -1;
				break;
			}
		} else if (arr[i] > ave) {
			if (judge(ave, arr[i])) {
				ans = -1;
				break;
			}
			ans += (arr[i] - ave) / 2;
		}
	}


	std::cout << ans << std::endl;

	return 0;
}
