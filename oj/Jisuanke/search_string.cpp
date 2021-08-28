/*************************************************************************
	> File Name: search_string.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年04月11日 星期三 15时57分52秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {

    int ans;
    string s1, s2, s1_temp;

    ans = 0;
    
    getline(cin, s1);
    getline(cin, s2);

    for(int i = 0; i < s1.size(); i++) {
        s1_temp.assign(s1, i, s2.size());
        if(s1_temp == s2) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
 * 计蒜客习题：寻找字符串；
 */
