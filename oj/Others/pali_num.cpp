/*************************************************************************
	> File Name: pali_num.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月18日 星期日 10时27分50秒
 ************************************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int reverse(int forward) {
    int backword = 0;
    while(forward) {
        backword = backword * 10 + forward % 10;
        forward /= 10;
    }
    return backword;
}

int main() {
    int Forward, Backword;
    vector<int> ans;

    ans.clear();
    cin >> Forward;
    ans.push_back(Forward);
    Backword = reverse(Forward);

    while(Forward != Backword) {
        Forward += Backword;
        ans.push_back(Forward);
        Backword = reverse(Forward);
        assert(Forward > 0);
    }

    cout << ans.size() - 1 << endl;
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++) {
        cout << "--->" << ans[i];
    }
    cout << endl;

    return 0;

}
