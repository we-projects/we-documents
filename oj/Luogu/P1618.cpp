/*************************************************************************
	> File Name: P1618.cpp
	> Author: sunowsir
	> Mail: sunowsir@protonmail.com
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月16日 星期四 17时25分12秒
 ************************************************************************/

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int unum[10] = {0};

bool no_use(int n) {

    while (n) {

        int evnum = n % 10;
        if (evnum == 0 || unum[evnum]) {
            return false;
        }
        unum[evnum] = 1;
        n /= 10;
    }

    return true;

}

bool judge(int first, int second, int third) {

    if (second > third) {
        return false;
    }

    if (second < 100 || second >= 1000) {
        return false;
    }

    if (third < 100 || third >= 1000) {
        return false;
    }

    memset(unum, 0, sizeof(unum));

    if (!no_use(first)) {
        return false;
    }
    if (!no_use(second)) {
        return false;
    }
    if (!no_use(third)) {
        return false;
    }

    return true;

}

int main() {

    int a, b, c;
    bool have;

    have = false;
    cin >> a >> b >> c;

    for (int i = 100; i < 1000; i++) {
        double second, third;
        second = ceil((double)i / (double)a) * b;
        third = ceil((double)i / (double)a) * c;
        if (judge(i, second, third)) {
            have = true;
            cout << i << " " << second << " " << third << endl;
        }
    }

    if (!have) {
        cout << "No!!!" << endl;
    }

    return 0;
}
