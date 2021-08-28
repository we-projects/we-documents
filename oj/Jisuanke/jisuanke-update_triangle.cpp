/*************************************************************************
	> File Name: update_triangle.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年04月08日 星期日 19时40分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int floor;
    char input, start_c, mid;
    string s, res_s;
    floor = 0;
    res_s = "";
    s = "";


    cin >> input;

    //通过输入判断需要输出几层；
    floor = input;
    if(input >= 'A' && input <= 'Z') {
        floor -= 64;
        start_c = 'A';
    }
    else {
        floor -= 48;
        start_c = '1';
    }

    for(int i = 1; i <= floor; i++) {
        //空格的数量；
        string space_num = string(floor - i, ' ');
        if(i == 1) {
            res_s = "";
        }
        else {
            res_s += start_c + i - 2;
        }
        s = res_s;
        mid = start_c + i - 1;
        reverse(res_s.begin(), res_s.end());
        cout << space_num << s << mid << res_s << endl;
        res_s = s;
    }

    return 0;
}

/*
 *计蒜客习题：升级版三角形；
 *只需要考虑字母或者数字前面的空格就可以；
 */
