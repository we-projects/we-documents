/*
 *	 File Name:    P1981.cpp
 *	 Author:       sunowsir
 *	 Mail:         sunowsir@protonmail.com
 *	 Created Time: 2018年10月21日 星期日 16时04分15秒
 */

#include <bits/stdc++.h>

using namespace std;

int Calc(string str) {
    int sum, len, mul, num;
    char oper;
    sum = 0;
    mul = 1;
    num = 0;
    len = str.size();

    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case '+' : sum += (num * mul) % 10000; mul = 1; num = 0; oper = '+'; break;
            case '*' : mul = (mul * num) % 10000; num = 0; oper = '*'; break;
            default : num = num * 10 + (str[i] - '0');
        }
        // cout << "num : " << num << " mul : " << mul << " sum : " << sum << endl;
    }

    sum += (mul * num) % 10000;

    return sum;
}

int main() {

    string calc_str = "";
    cin >> calc_str;

    cout << Calc(calc_str) % 10000 << endl;

    return 0;
}
