/*************************************************************************
	> File Name: P1426.cpp
	> Author: sunowsir
	> Mail:   sunowsir@protonmail.com
	> Created Time: 2018年08月18日 星期六 15时19分49秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {

    double s, x;

    cin >> s >> x;

    double l, r, dis, now_pos, last, need_time;

    l = s - x;
    r = s + x;
    now_pos = 0;
    dis = 0;
    last = 0;
    need_time = 0;

    for (int i = 1; now_pos <= r; i++) {
        if (now_pos >= l && now_pos <= r) {
            need_time++;
        }
        if (i == 1) {
            last = 7;
            dis = 7;
            now_pos = 7;
        } else {
            last = dis;
            dis = last * 0.98;
            now_pos += dis;
        }
    }

    if (now_pos <= r) {
        need_time++;
    }

    if (need_time < 2) {
        cout << "n" << endl;
    } else {
        cout << "y" << endl;
    }

    return 0;
}
