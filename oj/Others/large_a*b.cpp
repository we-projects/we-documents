/*************************************************************************
	> File Name: large_a*b.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月15日 星期四 17时26分58秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char char_a[510], char_b[510];
int a[510], b[510], c[1050];
int len_a, len_b, len_c;

int muti(int min_m[], int min_len, int max_m[], int max_len, int c[], int len_c) {
    int p, r;
    p = r = 0;
    for(int i = 0; i < min_len; i++) {
        for(int j = 0; j < max_len; j++) {
            c[i + j] += min_m[i] * max_m[j];
        }
    }

    for(int i = 0; i < len_c; i++) {
        if(c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }

    while(len_c > 1 && c[len_c - 1] == 0) {
        len_c--;
    }

    return len_c;
}

int main() {

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    scanf("%s %s", char_a, char_b);

    len_a = strlen(char_a);
    len_b = strlen(char_b);
    len_c = len_a + len_b;

    for(int temp = 0, i = len_a - 1; i>= 0; i--, temp++) {
        a[temp] = char_a[i] - '0';
    }
    for(int temp = 0, i = len_b - 1; i>= 0; i--, temp++) {
        b[temp] = char_b[i] - '0';
    }

    if(len_a > len_b) {
        len_c = muti(b, len_b, a, len_a, c, len_c);
    }
    else {
        len_c = muti(a, len_a, b, len_b, c, len_c);
    }

    for(int i = len_c - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;

    return 0;
}
