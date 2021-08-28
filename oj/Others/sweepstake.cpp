/*************************************************************************
	> File Name: sweepstake.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月22日 星期四 07时55分35秒
 ************************************************************************/

#include <iostream>
using namespace std;

bool judge(int num) {
    
    while(num) {
        int temp = num % 10;
        if(temp == 4) {
            return false;
        }
        num /= 10;
    }

    return true;
}

int main() {

    int num;
    num = 0;

    for(int i = 10000; i < 100000; i++) {
        if(judge(i)) {
            num++;
        }
    }

    cout << num << endl;

    return 0;
}
