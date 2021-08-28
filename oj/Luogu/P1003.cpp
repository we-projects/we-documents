/*************************************************************************
	> File Name: P1003.cpp
	> Author: sunowsir
	> Mail:   sunowsir@protonmail.com
	> Created Time: 2018年08月20日 星期一 16时45分37秒
 ************************************************************************/

#include <cstring>
#include <iostream>
using namespace std;

int main() {

    int n;
    int maps[100010][5];
    
    cin >> n;
    memset(maps, 0, sizeof(maps));
    for (int i = 0; i < n; i++) {
        cin >> maps[i][0] >> maps[i][1] >> maps[i][2] >> maps[i][3];
        maps[i][4] = i + 1;
    }

    int x, y;
    cin >> x >> y;

    int ans = -1;

    for (int i = 0; i < n; i++) {
        int x_range = maps[i][0] + maps[i][2];
        int y_range = maps[i][1] + maps[i][3];
        if (x >= maps[i][0] && x <= x_range && y >= maps[i][1] && y <= y_range) {
            ans = maps[i][4];
        }
    }

    cout << ans << endl;

    return 0;
}
