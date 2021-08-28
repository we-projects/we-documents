/*************************************************************************
	> File Name: poj2251.cpp
	> Author: sunowsir
	> GetHub:github.com/sunowsir/practice 
	> Created Time: 2017年10月15日 星期日 11时45分35秒
 ************************************************************************/

//自己用C语言实现广搜中的队列；

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

#define cls(x, y) memset(x, y, sizeof(x))
int L, R, C;
char Map[50][50][50];
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
bool book[50][50][50];

typedef struct Node {
    int x, y, z, s;
} Map_unit;


typedef struct Queue {
    Map_unit *data;
    int head, tail, length;
} Queue;

void init(Queue *q, int length) {
    q->data = (Map_unit *)malloc(sizeof(Map_unit) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
}

void push(Queue *q, Map_unit element) {
    if(q->tail + 1 > q->length) {
        return;
    }
    q->tail++;
    q->data[q->tail] = element;
    return;
}

Map_unit front(Queue *q) {
    return q->data[q->head];
}

void pop(Queue *q) {
    q->head++;
}

int empty(Queue *q) {
    return q->head > q->tail;
}

int size(Queue *q) {
    return q->tail - q->head + 1;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int check(int x, int y, int z) {
    if(x < 0 || x >= R || y < 0 || y >= C | z < 0 || z >= L) {
        return 0;
    }
    if(Map[x][y][z] == '#') {
        return 0;
    }
    if(book[x][y][z]) {
        return 0;
    }
    return 1;
}

void bfs(int start_x, int start_y, int start_z, int end_x, int end_y, int end_z) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 110000);
    cls(book, false);
    //把入口入队；
    Map_unit p, next;
    p.x = start_x;
    p.y = start_y;
    p.z = start_z;
    book[p.x][p.y][p.z] = true;
    p.s = 0;
    push(queue, p);
    while(size(queue)) {
        //取出队首元素；
        p = front(queue);
        pop(queue);
        //判断队首元素是否为出口；
        if(p.x == end_x && p.y == end_y && p.z == end_z) {
            printf("Escaped in %d minute(s).\n", p.s);
            clear(queue);
            return;
        }
        //六个方向搜;
        for(int i = 0; i < 6; i++) {
            //移动当前位置；
            next.x = dx[i] + p.x;
            next.y = dy[i] + p.y;
            next.z = dz[i] + p.z;
            //判断移动后的点是否真的可以移动，若能移动是否已经访问过；
            if(check(next.x, next.y, next.z)) {
                book[next.x][next.y][next.z] = true;
                next.s = p.s + 1;
                push(queue, next);
            }
        }
    }
    printf("Trapped!\n");
    clear(queue);
    return;
}

int main() {
    int start_x, start_y, start_z;
    int end_x, end_y, end_z;
    while(cin>> L >> R >> C && L + R + C) {
        cls(Map, 0);
        for(int i = 0; i < L; i ++) {
            for(int j = 0; j < R; j++) {
                for(int k = 0; k < C; k++) {
                    cin >> Map[j][k][i];
                    if(Map[j][k][i] == 'S') {
                        start_x = j;
                        start_y = k;
                        start_z = i;
                    }
                    if(Map[j][k][i] == 'E') {
                        end_x = j;
                        end_y = k;
                        end_z = i;
                    }
                }
            }
        }
        bfs(start_x, start_y, start_z, end_x, end_y, end_z);
    }
    return 0;
}
