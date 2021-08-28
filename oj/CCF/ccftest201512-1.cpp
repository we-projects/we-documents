/*************************************************************************
	> File Name: ccftest201512-1.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月15日 星期五 16时42分50秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main() {
    string num;
    int ans;
    ans = 0;
    cin >> num;
    for(int i = 0; i < num.size(); i++) {
        ans += num[i] - '0';
    }
    cout << ans << endl;
}
