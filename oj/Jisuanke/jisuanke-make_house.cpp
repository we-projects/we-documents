/*************************************************************************
	> File Name: make_house.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年04月08日 星期日 21时16分30秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {

    int n, m;
    char pre_de[110][110];

    cin >> n >> m;

    n = n * 2 + 1;
    m = m * 2 + 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i % 2 != 0 && j % 2 != 0) {
                pre_de[i][j] = '+';
            }
            else if(i % 2 != 0 && j % 2 == 0) {
                pre_de[i][j] = '-';
            }
            else if(i % 2 == 0 && j % 2 != 0) {
                pre_de[i][j] = '|';
            }
            else {
                pre_de[i][j] = '*';
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << pre_de[i][j];
        }
        cout << endl;
    }

    return 0;
}

/*
 * 计蒜客习题：造房子；
 */
