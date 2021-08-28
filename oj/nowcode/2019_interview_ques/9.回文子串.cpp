/*
	* File      : 9.回文子串.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Thu 26 Mar 2020 04:59:35 PM CST
*/

#include <iostream>
#include <string>

bool judge(std::string &str, int start, int end) {
	for (int i = start; i <  (end + start) >> 1; i++) {
		if (str[i] != str[str.size() - i]) return false;
	}
	return true;
}

int get(std::string &str) {
	int ans = 0;

	for (int i = 0; i < str.size(); i++) {
		
	}

	return ans;
}

int main() {
	std::string str;
	std::cin >> str;
	std::cout << get(str) << std::endl;
	return 0;
}
