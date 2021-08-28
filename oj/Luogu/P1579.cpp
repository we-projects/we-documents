/*************************************************************************
	> File Name: P1579.cpp
	> Author: sunowsir
	> Mail: sunowsir@protonmail.com
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月16日 星期四 18时19分02秒
 ************************************************************************/

#include <cstring>
#include <iostream>
using namespace std;

#define MAX_N 20010

int prime[MAX_N + 5];
bool isprime[MAX_N * 10];

void Init() {
    

    memset(prime, 0, sizeof(prime));
    memset(isprime, false, sizeof(isprime));
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

    Init();

    int n;
    bool flag;

    flag = true;
    cin >> n;

    for (int i = 1; prime[i] < MAX_N && flag; i++) {
        for (int j = 1; prime[j] < MAX_N; j++) {
            int third = n - prime[i] - prime[j];
            if (third > 1 && isprime[third] == 0) {
                cout << prime[i] << " " << prime[j] << " " << third  << endl;
                flag = false;
                break;
            }
        }
    }

    return 0;
}
