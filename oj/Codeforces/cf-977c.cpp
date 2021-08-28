/*************************************************************************
  > File Name: cf-977c.cpp
  > Author: sunowsir
  > GitHub: github.com/sunowsir
  > Created Time: 2018年05月09日 星期三 15时01分50秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 2e5;

int num[maxn];

int main () {

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);

    if (num[k - 1] != num[k] && num[k] - 1 != 0) {
        if (n == k) {
            cout << num[k - 1] << endl;
        }
        else {
            cout << num[k] - 1 << endl;
        }
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
}
