/*************************************************************************
	> File Name: ccftest201703-1.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月15日 星期五 15时32分15秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k, cake, cake_num, ans;
    ans = 0;
    cake_num = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &cake);
        if(cake_num < k) {
            cake_num += cake;
        }
        if(cake_num < k && i == (n - 1)) {
            ans++;
        }
        if(cake >= k || cake_num >= k) {
            ans++;
            cake_num = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
