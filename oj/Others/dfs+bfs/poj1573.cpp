/*************************************************************************
	> File Name: poj1573.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月02日 星期六 08时31分23秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

//搜索

#define cls(x, y)  memset(x, y, sizeof (x) )
char instr_map[110][110];
int step[110][110];
bool book[110][110];
int step_num, n, m;

void  DFS (int move_x, int move_y, int &step_num) {
    if ( move_x < 0 || move_x >= n || move_y < 0 || move_y >= m ) {
        printf ("%d step(s) to exit\n", step_num);
        return;
    }
    if ( book[move_x][move_y] ) {
        printf ("%d step(s) before a loop of %d step(s)\n", step[move_x][move_y], step_num - step[move_x][move_y]);
        return;
    }
    book[move_x][move_y] = true;
    step[move_x][move_y] = step_num;
    int next_x, next_y;
    next_x=0;
    next_y=0;
    if ( instr_map[move_x][move_y] == 'S' ) {
        next_x = move_x + 1;
        next_y = move_y;
    }
    if ( instr_map[move_x][move_y] == 'N' ) {
        next_x = move_x - 1;
        next_y = move_y;
    }
    if ( instr_map[move_x][move_y] == 'E' ) {
        next_x = move_x;
        next_y = move_y + 1;
    }
    if ( instr_map[move_x][move_y] == 'W' ) {
        next_x = move_x;
        next_y = move_y - 1;
    }
    DFS (next_x, next_y, step_num += 1);
}

int main () {
    int input_y;
    while ( cin >> n >> m >> input_y, n, m, input_y) {
        cls (step, 0);
        cls (book, false);
        step_num = 0;
        for ( int i = 0; i < n; i++ ) {
            cin >> instr_map[i];
        }
        DFS(0, input_y-1, step_num);
    }
    return 0;
}
