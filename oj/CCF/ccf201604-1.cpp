/*************************************************************************
	> File Name: ccf201604-1.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月15日 星期五 16时19分32秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, num, last_num, ans, wave, last_wave;
    last_num = 0;
    ans = 0;
    wave = 0;
    last_wave = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(last_num < num) {
            wave = 1;
        }
        else {
            wave = -1;
        }
        last_num = num;
        if(i == 1) {
            last_wave = wave;
        }
        if(i > 1) {
            if(last_wave != wave) {
                ans++;
            }
            last_wave = wave;
        }
    }
    cout << ans << endl;
    return 0;
}
