/*************************************************************************
	> File Name: lanqiao_int_x.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月15日 星期四 20时34分18秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {

    int n, x, ans;
    ans = 0;

    cin >> n >> x;

    int num[n + 5];
    
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for(int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum += num[j];
            }
        }
        if(sum == x) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
