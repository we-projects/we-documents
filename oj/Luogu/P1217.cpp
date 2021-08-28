/*************************************************************************
    > File Name: P1217.cpp
    > Author: sunowsir
    > Mail: sunowsir@protonmail.com
    > GitHub: github.com/sunowsir
    > Created Time: 2018年08月16日 星期四 10时14分18秒
 ************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

bool is_Prime(int64_t num) {

    for (int64_t i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;

}

bool judge(int num) {


    int rec, n;
    rec = 0;
    n = num;

    while (n) { 
        rec = rec * 10 + n % 10;
        n /= 10;
    }

    return rec == num;

}

int main() {

    int64_t left, right;

    while (cin >> left >> right) {
        
        for (int64_t i = left; i <= right; i++) {
            if (i == 12) {
                i += 86;
            }
            if (i == 1000) {
                i += 999;
            }
            if (i == 100000) {
                i += 99999;
            }
            if (i == 10000000) {
                break;
            }
            if (i % 2 == 0 && i != 2) {
                continue;
            }
            if (judge(i) && is_Prime(i)) {
                printf("%d\n", i);
            }
        }
        
    }

    return 0;
}
