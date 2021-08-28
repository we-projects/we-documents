/*************************************************************************
	> File Name: lanqiao_sanyangxianrui.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年04月03日 星期二 20时16分07秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int judge(int a, int b, int  s) {
    int y, len_x, len_y, len_s;
    int xx[5], yy[5], ss[6], flag[10];
    memset(xx, 0, sizeof(xx));
    memset(yy, 0, sizeof(yy));
    memset(ss, 0, sizeof(ss));
    memset(flag, 0, sizeof(flag));
    len_x = 0;
    len_y = 0;
    len_s = 0;
    y = b;

    while(a) {
        int temp = a % 10;
        xx[len_x++] = temp;
        flag[temp]++;
        a /= 10;
    }
    while(b) {
        int temp = b % 10;
        yy[len_y++] = temp;
        flag[temp]++;
        b /= 10;
    }
    while(s) {
        ss[len_s++] = s % 10;
        s /= 10;
    }
    flag[ss[0]]++;
    flag[yy[0]]--;
    for(int i = 0; i < 10; i++) {
        if(flag[i] > 1) {
            return -1;
        }
    }
    if(len_s == 4) {
        return -1;
    }
    if(ss[1] == xx[2] && ss[2] == xx[1] && ss[3] == yy[2] && ss[4] == yy[3] && xx[2] == yy[0]) {
        return y;
    }

    return -1;

}

int main() {

    bool flag = false; 

    for(int i = 1000; i < 9999; i++) {
        for(int j = 1000; j < 9999; j++) {
            int ans = judge(i, j, i + j);
            if(ans != -1) {
                flag = true;
                cout << ans << endl;
                break;
            }
        }
        if(flag) {
            break;
        }
    }

    if(!flag) {
        cout << "false" << endl;
    }

    return 0;
}
