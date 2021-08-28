/*
	* File      : 3.今年的第几天.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sat 21 Mar 2020 08:23:04 PM CST
*/

#include <iostream>
#include <vector>

int main() {
	int y, m, d, ans;
	ans = 0;
	std::vector<int> m_nums = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	std::cin >> y >> m >> d;
	if ((y % 4 == 0 && y % 100 != 0 ) || y % 400 == 0) ans++;
	ans += m_nums[m - 1] + d;
	std::cout << ans << std::endl;
	return 0;
}
