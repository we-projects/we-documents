/*************************************************************************
	> File Name: P1014.cpp
	> Author: sunowsir
	> Mail:   sunowsir@protonmail.com
	> Created Time: 2018年08月18日 星期六 20时17分22秒
 ************************************************************************/

#include <cstring>
#include <iostream>
using namespace std;

#define MAX_N 100000

int tabs[MAX_N + 5];

void Init() {

    memset(tabs, 0, sizeof(tabs));
    for (int i = 1; i < MAX_N; i++) {
        tabs[i] = i + tabs[i - 1];
    }

    return;

}

int main() {

    Init();

    int n;

    cin >> n;

    for (int i = 1; i < MAX_N; i++) {

        if (n >= tabs[i] && n < tabs[i + 1]) {

            if (n == tabs[i]) {
                if (i % 2 == 0) {
                    cout << i << "/1" << endl;
                }
                else {
                    cout << "1/" << i << endl;
                }
            }
            else {
                if (i % 2 == 0) {
                    cout << (i + 1) - (n - tabs[i]) + 1 << "/" << n - tabs[i] << endl;
                }
                else {
                    cout << n - tabs[i] << "/" << (i + 1) - (n - tabs[i]) + 1 << endl;
                }
            }
            break;
        }

    }



    return 0;
}
