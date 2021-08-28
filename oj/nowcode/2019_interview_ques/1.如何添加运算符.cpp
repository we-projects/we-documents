/*
	* File      : 1.如何添加运算符.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sat 21 Mar 2020 02:30:40 PM CST
*/

#include <iostream>
#include <stack>

bool judge(std::string formular, int m) {
	// formular.erase(0, 1);
	if (formular.size() == 1) return ((formular[0] - '0') == m);

	std::stack<int> num;
	std::stack<char> ope;
	int now_num = 0;
	int res = 0;

	for (int i = 0; i < formular.size(); i++) {
		if (formular[i] == ' ') continue;
		else if (formular[i] == '+' || formular[i] == '-') ope.push(formular[i]), num.push(now_num) ,now_num = 0;
		else now_num = now_num * 10 + (formular[i] - '0');
	}

	if (now_num) num.push(now_num);
	if (num.size() == 1) return (num.top() == m);

	while (!num.empty() && !ope.empty()) {
		int cal_num1 = num.top();
		num.pop();
		int cal_num2 = num.top();
		num.pop();

		num.push((ope.top() == '+') ? (cal_num2 + cal_num1) : (cal_num2 - cal_num1));
		res = num.top();

		ope.pop();
	}

	return (res == m);
}

int get(int start, int end, int m, std::string formular) {
	if (start > end) {
		return judge(formular, m);
	} 
	
	int ans = 0;

	ans = get(start + 1, end, m, std::string(formular + "+") + std::to_string(start));
	ans += get(start + 1, end, m, std::string(formular + "-") + std::to_string(start));
	ans += get(start + 1, end, m, std::string(formular + " ") + std::to_string(start));

	return ans;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::cout << get(2, n, m, std::string("1"))<< std::endl;
	return 0;
}
