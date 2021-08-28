/*************************************************************************
	> File Name: P1036.cpp
	> Author: sunowsir
	> Mail: sunowsir@protonmail.com
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月15日 星期三 20时43分55秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 5000000

int prime[MAX_N] = {0};
int isprime[MAX_N * 20] = {0};

void is_Prime() {
    
    for (int i = 2; i < MAX_N * 5; i++) {
        if (!isprime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N * 5; j++) {
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    return;

}

int main() {

    is_Prime();

    int n, k;
    int num[25];

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int ans = 0;

    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        int nnum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                nnum++;
                sum += num[j];
            }
        }
        if (nnum == k && isprime[sum] == 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
