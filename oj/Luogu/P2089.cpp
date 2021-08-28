/*************************************************************************
	> File Name: P2089.cpp
	> Author: sunowsir
	> Mail: sunowsir@protonmail.com
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月16日 星期四 19时47分52秒
 ************************************************************************/

#include <cstring>
#include <iostream>
using namespace std;

int prog[600000][15];
int ans, n;

void dfs(int pros, int sum) {
    
    if (pros == 10 && sum != n) {
        return;
    }

    if (sum > n) {
        return;
    }

    if (pros == 10 && sum == n) {
        ans++;
        if (ans > 0) {
            for (int i = 1; i <= pros; i++) {
                prog[ans][i] = prog[ans - 1][i];
            }
        }
        return;
    }
    
    for (int i = 1; i < 4; i++) {
        sum += i;
        pros++;
        prog[ans][pros] = i;
        dfs(pros, sum);
        sum -= i;
        pros--;
    }

    return;

}

int main() {

    memset(prog, 0, sizeof(prog));
    ans = 0;

    cin >> n;

    dfs(0, 0);


    cout << ans << endl;

    for (int i = 0; i < ans; i++) {
        for (int j = 1; j <= 10; j++) {
            if (j > 1) {
                cout << " ";
            }
            cout << prog[i][j];
        }
        cout << endl;
    }

    return 0;
}
