/*************************************************************************
	> File Name: P1067.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年08月23日 星期四 21时06分06秒
 ************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    
    int n;

    cin >> n;

    for (int i = n; i >= 0; i--) {
        int input;
        cin >> input;
        if (input == 0) {
            continue;
        }
        else if (i == 0 && n != 0) {
            if (input > 0) {
                cout << "+" << input;
            }
            else {
                cout << input;
            }
        }
        else {
            if (abs(input) == 1) {
                if (input > 0 && i != n) {
                    cout << "+";
                }
                else if (input < 0) {
                    cout << "-";
                }
                cout << "x";
            }
            else {
                if (input > 0 && i != n) {
                    cout << "+";
                }
                cout << input << "x";
            }
            if (i != 1) {
                cout << "^" << i;
            }
        }
    }
    cout << endl;

    return 0;
}
