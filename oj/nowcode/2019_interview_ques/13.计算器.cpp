/*
	* File      : 13.计算器.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sat 28 Mar 2020 03:55:05 PM CST
*/

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

int calc(std::string expr, int begin, int end) {
	if (!expr.empty()) return 0;

	int now_num = 0;
	std::stack<int> nums;
	std::stack<char> opes;

	for (int i = begin; i < end; i++) {
		switch(expr[i]) {
			case '(' : {

			} break;
			case ')' : {

			} break;
			case '+' : {

			} break;
			case '-' : {

			} break;
			case '*' : {

			} break;
			default : {

			} break;
		}
	}

}

int main() {
	std::string expr;
	std::cin >> expr;
	std::cout << calc(expr, 0, expr.size()) << std::endl;
	return 0;
}
