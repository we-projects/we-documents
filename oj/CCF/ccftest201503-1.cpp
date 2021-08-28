/*************************************************************************
	> File Name: ccftest201503-1.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月15日 星期五 17时05分29秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int num[1100][1100];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> num[i][j];
        }
    }
    for(int i = (m - 1); i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(j != 0) {
                cout << " ";
            }
            cout << num[j][i];
        }
        cout << "\n";
    }
    cout << endl;
    return 0;
}
