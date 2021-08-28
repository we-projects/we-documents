/*************************************************************************
	> File Name: P1464.cpp
	> Author: sunowsir
	> Mail:   sunowsir@protonmail.com
	> Created Time: 2018年08月18日 星期六 16时46分16秒
 ************************************************************************/

#include <cstring>
#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 55

int mem[MAX_N][MAX_N][MAX_N];

int64_t W_Fun(int64_t a, int64_t b, int64_t c) {

    if (a <= 0 || b <= 0 || c <= 0)  {
        return 1;
    } 
    else if (a > 20 || b > 20 || c > 20) {
        return W_Fun(20, 20, 20);
    }
    else if (mem[a][b][c] != 0) {
        return mem[a][b][c];
    }
    else if (a < b && b < c) {
        mem[a][b][c] = W_Fun(a, b, c - 1) + W_Fun(a, b - 1, c - 1) - W_Fun(a, b - 1, c);
        return mem[a][b][c];
    }
    else {
        mem[a][b][c] = W_Fun(a - 1, b, c) + W_Fun(a - 1, b - 1, c) + W_Fun(a - 1, b, c - 1) - W_Fun(a - 1, b - 1, c - 1);
        return mem[a][b][c];
    }

    return mem[a][b][c];

}

int main() {

    int64_t a, b, c;

    memset(mem, 0, sizeof(mem));

    while (cin >> a >> b >> c) {

        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << W_Fun(a, b, c) << endl;

    }

    return 0;
}
