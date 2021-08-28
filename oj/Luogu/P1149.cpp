/*************************************************************************
	> File Name: P1149.cpp
	> Author: sunowsir
	> Mail: sunowsir@protonmail.com
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月15日 星期三 22时28分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int Get_N(int n) {

    if (n < 10) {
        return num[n];
    }

    int ans;

    ans = 0;

    while (n) {
        ans = ans + num[n % 10];
        n /= 10;
    }

    return ans;

}

int main() {

    int n, ans;

    cin >> n;

    n -= 4;
    ans = 0;


    for (int i = 0; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {

            if (Get_N(i) + Get_N(j) + Get_N(i + j) == n) {
                ans ++;
                if (i != j) {
                    ans++;
                }
            }

        }
    }

    cout << ans << endl;

    return 0;
}
