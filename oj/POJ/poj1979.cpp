/*************************************************************************
	> File Name: poj1979.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2018年03月12日 星期一 18时15分46秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char Map[25][25];
bool book[25][25];
int x, y;

void traverse(int sx, int sy, int *num) {
    book[sx][sy] = true;
    //判断是否越界；
    if(sx < 0 || sx >= x || sy < 0 || sy >= y) {
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if(!book[nx][ny] && nx >= 0 && nx < x && ny >= 0 && ny < y && Map[nx][ny] != '#') {
            (*num)++;
            traverse(nx, ny, num);
        }
    }
    return;

}

int main() {

    int start_x, start_y, num;

    while(cin >> y >> x && x != 0 && y != 0) {
        num = 1;
        memset(book, false, sizeof(book));
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                cin >> Map[i][j];
                if(Map[i][j] == '@') {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        traverse(start_x, start_y, &num);
        cout << num << endl;
    }

    return 0;
}
