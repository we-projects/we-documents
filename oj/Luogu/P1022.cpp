/*************************************************************************
	> File Name: P1022.cpp
	> Author: sunowsir
	> Mail:   sunowsir@protonmail.com
	> Created Time: 2018年08月19日 星期日 21时54分05秒
 ************************************************************************/

#include <cstdio>
#include <sstream>
#include <iostream>
using namespace std;

int main() {

    string equ, strnums;
    int equ_len;
    double vnums, nums;
    char var, eq, oper;

    cin >> equ;
    oper = '+';
    eq = '0';
    strnums = "";
    vnums = 0;
    nums = 0;
    equ_len = equ.size();

    for (int i = 0; i < equ_len; i++) {

        
        if (equ[i - 1] == '=') {
            if (equ[i] == '-') {
                oper = '-';
                i++;
            }
            else {
                oper = '+';
            }
            eq = '=';

        }

        if (equ[i] >= '0' && equ[i] <= '9') {
            strnums = strnums + equ[i];
        }
        else if (equ[i] >= 'a' && equ[i] <= 'z') {
            if (eq == '=') {
                if (oper == '+') {
                    oper = '-';
                }
                else {
                    oper = '+';
                }
            }
            stringstream ss;
            int temp;
            if (strnums != "") {
                ss << strnums;
                ss >> temp;
            }
            else {
                temp = 1;
            }
            if (oper == '-') {
                vnums -= temp;
            }
            else {
                vnums += temp;
            }
            strnums = "";
            var = equ[i];
            oper = equ[i + 1];
            i++;
        }
        else {
            if (eq == '=') {
                if (oper == '+') {
                    oper = '-';
                }
                else {
                    oper = '+';
                }
            }
            stringstream ss;
            int temp;
            if (strnums != "") {
                ss << strnums;
                ss >> temp;
            }
            else {
                temp = 0;
            }
            if (oper == '-') {
                nums -= temp;
            }
            else {
                nums += temp;
            }
            //cout << "num : i = " << i << " temp = " << temp << " nums = " << nums << endl;
            strnums = "";
            oper = equ[i];
        }
        if (equ[equ_len - 1] != var && i == equ_len - 1) {
            if (eq == '=') {
                if (oper == '+') {
                    oper = '-';
                }
                else {
                    oper = '+';
                }
            }
            stringstream ss;
            int temp;
            if (strnums != "") {
                ss << strnums;
                ss >> temp;
            }
            else {
                temp = 0;
            }
            if (oper == '-') {
                nums -= temp;
            }
            else {
                nums += temp;
            }
            
        }
        
    }

    double ans = (0 - nums) / vnums;

    if (ans == 0) {
        cout << var << "=0.000" << endl;
    }
    else {
        printf("%c=%.3lf\n", var, ans);
    }

    //cout << "nums = " << nums << " vnums = " << vnums << endl;

    return 0;
}
