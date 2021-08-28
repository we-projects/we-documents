/*************************************************************************
	> File Name: kindergarten.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年04月06日 星期五 16时52分52秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {

    int n, m, k, ans, max_ans;
    ans = 0;
    max_ans = -1;
    int need[110][20];
    memset(need, 0, sizeof(need));

    cin >> n >> m >> k;

    bool everyone[k + 5];

    for(int i = 0; i < n; i++) {
        cin >> need[i][0];
        for(int j = 1; j <= need[i][0]; j++) {
            cin >> need[i][j];
        }
    }
    
    //binary enumeration
    for(int i = 0; i < (1 << k); i++) {
        int num = 0;

        for(int j = 0; j <= k; j++) {
            everyone[j] = false;
        }

        //坑，循环里面的j是二进制1后面几个零，而例如1后面一个零，代表的是2号玩具；
        for(int j = 0; j < k; j++) {
            if(i & 1 << j) {
                num++;
                everyone[j + 1] = true;
            }
        }
        if(num == m) {
            ans = 0;
            for(int j = 0; j < n; j++) {
                bool temp = true;
                for(int kk = 1; kk <= need[j][0]; kk++) {
                    //if(need[j][0] == 0) {
                    //    ans++;
                    //    break;
                    //}
                    if(!everyone[need[j][kk]]) {
                        temp = false;
                    }
                }
                if(temp) {
                    ans++;
                }
            }
            max_ans = max(max_ans, ans);
            
        }
    }

    cout << max_ans << endl;

    return 0;
}

/*
 * 计蒜客习题：幼儿园买玩具；
 */
