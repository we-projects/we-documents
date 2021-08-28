/*************************************************************************
	> File Name: ccftest201509-1.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月15日 星期五 16时50分21秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, num, head, ans;
    ans = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(i == 0) {
            head = num;
        }
        if(i > 0) {
            if(head != num) {
                ans++;
                head = num;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
