/*************************************************************************
> File Name: cf-976a.cpp
> Author: sunowsir
> GitHub: github.com/sunowsir
> Created Time: 2018年05月02日 星期三 19时31分40秒
************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, num_0;
    string binary, ans;
    num_0 = 0;
    cin >> n;
    cin >> binary;
    ans = binary[0];

    num_0 = count(binary.begin(), binary.end(), '0');
    if (num_0 != 0 && ans != "0") {
        ans.insert(ans.end(), num_0, '0');
    }

    cout << ans << endl;
    return 0;
}
