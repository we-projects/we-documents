/*************************************************************************
> File Name: cross_map.cpp
> Author: sunowsir
> GitHub: github.com/sunowsir
> Created Time: 2018年04月10日 星期二 21时04分58秒
************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main() {

    int n, xy_num;

    cin >> n;

    xy_num = n * 4 + 5;

    char Map[xy_num + 5][xy_num + 5];

    memset(Map, '.', sizeof(Map));

    //从最外圈往里画正方形；
    bool temp = false;
    for(int i = 1; i <= xy_num / 2; i++) {
        if(i % 2 != 0) {
            temp = true;
        }
        for(int j = i; j <= xy_num - i + 1; j++) {
            if(temp) {
                Map[i][j] = '$';
                Map[xy_num - i + 1][j] = '$';
                Map[j][i] = '$';
                Map[j][xy_num - i + 1] = '$';
            }
        }
        temp = false;
    }

    for(int i = 1; i <= xy_num / 2; i++) {
        if(i % 2 != 0) {
            temp = true;
        }
        for(int j = i; j <= xy_num - i + 1; j++) {

            if(i == j && i == 1) {
                Map[i][j] = '.';
                Map[i][xy_num - i + 1] = '.';
                Map[xy_num - i + 1][j] = '.';
                Map[xy_num - i + 1][xy_num - i + 1] = '.';
            }

            if(j == i && temp) {
                Map[i][j + 1] = '.';
                Map[i + 1][j + 2] = '$';
                Map[i + 1][j] = '.';
                Map[i + 2][j + 1] = '$';

                Map[i][xy_num - i] = '.';
                Map[i + 1][xy_num - i - 1] = '$';
                Map[i + 1][xy_num - i + 1] = '.';
                Map[i + 2][xy_num - i] = '$';

                Map[xy_num - i + 1][j + 1] = '.';
                Map[xy_num - i][j + 2] = '$';
                Map[xy_num - i][j] = '.';
                Map[xy_num - i - 1][j + 1] = '$';

                Map[xy_num - i + 1][xy_num - i] = '.';
                Map[xy_num - i][xy_num - i -1] = '$';
                Map[xy_num - i][xy_num - i + 1] = '.';
                Map[xy_num - i - 1][xy_num - i] = '$';

            }
        }
        temp = false;
    }

    Map[(xy_num + 1) / 2][(xy_num + 1) / 2] = '$';


    //测试正方形是否正常画出；
    for(int i = 1; i <= xy_num; i++) {
        for(int j = 1; j <= xy_num; j++) {
            cout << Map[i][j];
        }
        cout << endl;
    }

    return 0;
}
/*
 * 计蒜客习题（蓝桥杯真题）：十字图；
 */
