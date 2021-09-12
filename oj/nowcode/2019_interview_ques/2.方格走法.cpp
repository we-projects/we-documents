/*
	* File      : 2.方格走法.cpp
	* Author    : sunowsir
	* Mail      : sunowsir@163.com
	* Creation  : Sat 21 Mar 2020 06:23:17 PM CST
*/

#include <iostream>
using namespace std;

int main() {
    long long int x, y, ans = 1;
    cin >> x >> y;
	if (x < y) std::swap(x, y);
    for (int i = x + y; i >= x; i--) {
        ans *= i;
    }
    for (int i = 2; i <= x; i++) {
        ans /= i;
    }
    cout << ans << endl;
    return 0;
}
