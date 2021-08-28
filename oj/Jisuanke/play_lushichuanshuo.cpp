/*************************************************************************
	> File Name: play_lushichuanshuo.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年04月07日 星期六 22时54分08秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n, sum_cost, sum_w, min_cost, max_w;
    int cards[11][5];
    bool flag;
    min_cost = 1100;
    max_w = 0;
    flag = false;

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> cards[i][j];
            if(j == 1 && cards[i][j] == 0) {
                flag = true;
            }
        }
    }

    if(flag) {
        for(int i = 0; i < (1 << n); i++)  {
            flag = false;
            sum_cost = 0;
            sum_w = 0;
            for(int j = 0; j < n; j++) {
                if(i & 1 << j) {
                    if(cards[j][1] == 0) {
                        flag = true;
                    }
                    //总的法力值消耗；
                    sum_cost += cards[j][0];
                    //总的攻击力；
                    sum_w += cards[j][2];
                }
            }
            if(sum_cost <= 10 && flag) {
                min_cost = min(min_cost, sum_cost);
                max_w = max(max_w, sum_w);
            }
        }

        cout << max_w << endl;

    }
    else {
        cout << 0 << endl;
    }
    
    return 0;
}
/*
 * 计蒜客习题：islands打炉石传说；
 */
