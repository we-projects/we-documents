/*************************************************************************
	> File Name: P1028.cpp
	> Author: sunowsir
	> Mail: sunowsir@protonmail.com
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月15日 星期三 16时40分57秒
 ************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

int ans = 1;
int dp[1010] = {0};

void let(int num) {

    if (dp[num] != 0) {
        return;
    }
    if ((num - 1) / 2 == num / 2) {
        dp[num] = dp[num - 1];
    }

    int ans = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (dp[i] != 0) {
            ans += dp[i];
            continue;
        }
        let(i);
        ans++;

    }

    dp[num] = ans + 1;

}

int main() {

    int n;

    dp[1] = 1;
    cin >> n;

    let(n);

    for (int i = 1; i <= n / 2; i++) {
        ans += dp[i];
    }

    cout << ans << endl;

    return 0;
}
