/*************************************************************************
	> File Name: reverse.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月22日 星期四 21时02分53秒
 ************************************************************************/

#include <iostream>
using namespace std;

int reverse(int n) {
    
    int res = 0;
    
    while(n) {
        res = res * 10 + n % 10;
        n /= 10;
    }

    return res;

}

int main() {
    
    int n, res_n;

    cin >> n;

    cout << reverse(n) << endl;

    return 0;

}
