/*************************************************************************
	> File Name: flnor.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月22日 星期四 07时35分09秒
 ************************************************************************/

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool judge(int num) {
    int n, sum;
    n = num;
    sum = 0;
    while(num) {
        sum += pow(num % 10, 4);
        num /= 10;
    }
    if(sum == n) {
        return true;
    }
    return false;
}

int main() {

    vector<int> num;

    for(int i = 1000; i < 10000; i++) {
        if(judge(i)) {
            num.push_back(i);
        }
    }

    sort(num.begin(), num.end());

    vector<int>::iterator it = num.begin();
    for(;it < num.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}
