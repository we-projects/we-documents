/*************************************************************************
	> File Name: hdu-2897.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月18日 星期日 10时56分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, p, q;

    while(~scanf("%d %d %d", &n, &p, &q)) {
        
        int temp = n % (p + q);

        if(temp > 0 && temp <= p) {
            cout << "LOST" << endl;
        }
        else {
            cout << "WIN" << endl;
        }

    }

    return 0;

}
