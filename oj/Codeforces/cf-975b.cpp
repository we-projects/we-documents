/*************************************************************************
	> File Name: cf-975b.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年05月05日 星期六 18时24分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main () {

    long long pebble[14], maxn, max_ip;

    for (int i = 0; i < 14; i++) {
        cin >> pebble[i];
        if (i == 0) {
            maxn = pebble[i];
        }
        else {
            if (maxn < pebble[i]) {
                maxn = pebble[i];
                max_ip = i;
            }
        }
        pebble[max_ip] = 0;
    }

    long long circle, surplus, ans;
    circle = maxn / 14;
    surplus = maxn % 14;

    for (int i = 1; i <= surplus; i++) {
        pebble[max_ip + i]++;
    }

    pebble[max_ip] = circle;

    for (int i = 0; i < 14; i++) {
        int temp_p = pebble[i] % 2;
        int temp_c = circle % 2;
        if ((temp_p == 0 && temp_c == 0) || ( temp_p != 0 && temp_c != 0 )) {
            ans += (pebble[i] + circle);
        }
    }

    cout << ans << endl;

    return 0;
}
