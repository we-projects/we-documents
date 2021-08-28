/*************************************************************************
	> File Name: cf946a.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2018年03月10日 星期六 14时45分07秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {

    int sum_a, sum_b, num, n;
    sum_b = sum_a = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num >= 0) {
            sum_b += num;
        }
        else {
            sum_a += num;
        }
    }

    cout << sum_b - sum_a << endl;

    return 0;
}
