/*************************************************************************
	> File Name: cf-977a.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年05月09日 星期三 14时09分58秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main () {

    int num, k;

    cin >> num >> k;

    while (k--) {
        if (num % 10 == 0) {
            num /= 10;
        }
        else {
            num--;
        }
    }

    cout << num << endl;

    return 0;
}
