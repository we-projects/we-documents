/*************************************************************************
	> File Name: three_equqtion.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月22日 星期四 22时01分06秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int a, b, c;
    a = 0;
    b = 0;
    c = 0;

    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            double temp = sqrt(1000 - i * i - j * j);
            c = (int)temp;
            if(c == temp) {
                cout << i << " " << j << " " << c << endl;
            }
        }
    }

    return 0;
}
