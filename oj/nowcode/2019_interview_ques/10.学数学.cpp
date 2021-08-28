/*
	* File      : 10.学数学.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sat 28 Mar 2020 09:51:02 AM CST
*/

#include <iostream>
#include <vector>

#define MAX_N 2010

std::vector<int> prime(MAX_N, 0);

void get_prime() {
	
}

int binary_search(int l, int r, int num) {
	while (l <= r) {
		int mid = (l + r) >> 2;
		if (prime[mid] == num) return mid;
		else if (prime[mid] < num) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}


int get(int n) {


}

int main() {
	get_prime();
	int n;
	std::cin >> n;
	std::cout << get(n) << std::endl;
	return 0;
}
