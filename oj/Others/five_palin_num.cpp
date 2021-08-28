/*************************************************************************
	> File Name: five_palin_num.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月22日 星期四 20时57分13秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int reverse_int(int num) {
    
    int res_n;
    res_n = 0;

    while(num) {
        res_n = res_n * 10 + num % 10;
        num /= 10;
    }

    return res_n;

}

int every_sum(int num) {
    
    int sum;
    sum = 0;

    while(num) {
        sum += num % 10;
        num /= 10;
    }

    return sum;

}

int main() {

    int n, num[900005], j;

    j = 0;
    cin >> n;
    memset(num, 0, sizeof(num));

    for(int i = 10000; i < 1000000; i++) {
        
        int res_n = reverse_int(i);

        if(reverse_int(i) == i && every_sum(i) == n) {
            num[j++] = i;
        }

    }

    if(j != 0) {
        
        for(int i = 0; i < j; i++) {
    
            cout << num[i] << endl;
    
        }
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
}
