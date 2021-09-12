/* 
 * File Name:    jisuanke_heap2.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年11月02日 星期五 15时52分44秒
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct Node {
    int index, dis;
} Node;

bool NodeCmd(Node a, Node b) {
    if (a.dis == b.dis) {
        return a.index < b.index;
    }
    return a.dis > b.dis;
}

typedef struct Heap {
    Node *data;
    int size, length;
} Heap;

#define swap(a, b) { \
    __typeof(a) __temp; \
    (__temp) = (a); \
    (a) = (b); \
    (b) = (__temp); \
}

Heap *init(int size) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (Node *)malloc(sizeof(Node) * size);
    h->size = size;
    h->length = 0;
    return h;
}

bool HeapEmpty(Heap *h) {
    return h->length == 0;
}

bool HeapPush(Heap *h, Node data) {
    if (h->length >= h->size) {
        return false;
    }
    int current, father;
    current = h->length;
    father = (current - 1) / 2;
    h->data[h->length] = data;
    h->length++;
    while (NodeCmd(h->data[current], h->data[father])) {
        swap(h->data[current], h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    return true;
}

void HeapUpdate(Heap *h, int index) {
    int max_ind, lchild, rchild;
    max_ind = index;
    lchild = index * 2 + 1;
    rchild = index * 2 + 2;
    if (lchild < h->length && NodeCmd(h->data[lchild], h->data[max_ind])) {
        max_ind = lchild;
    }
    if (rchild < h->length && NodeCmd(h->data[rchild], h->data[max_ind])) {
        max_ind = rchild;
    }
    if (max_ind != index) {
        swap(h->data[index], h->data[max_ind]);
        HeapUpdate(h, max_ind);
    }
    return ;
}

bool HeapPop(Heap *h) {
    if (HeapEmpty(h)){
        return false;
    }
    h->length--;
    swap(h->data[0], h->data[h->length]);
    HeapUpdate(h, 0);
    return true;
}

Node HeapTop(Heap *h) {
    return h->data[0];
}

bool HeapClear(Heap *h) {
    if (h == NULL) {
        return false;
    }
    free(h->data);
    free(h);
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n;
        /* 速度相同的僵尸放到一个堆里，根据题目数据范围：s < 0 && s >= 100 */
        Heap *h[101];
        cin >> n;
        for (int i = 1; i <= 100; i++) {
            h[i] = init(n);
        }

        for (int i = 0; i < n; i++) {
            int f, s;
            cin >> f >> s;
            Node zombie;
            zombie.index = i + 1;
            zombie.dis = f;
            /* 速度相同的僵尸，排名不变 */
            HeapPush(h[s], zombie);
        }

        cout << "Case #" << k << ":" << endl;

        /* 不断的从所有的１０１个堆中挑出最大的堆顶，然后弹出  */
        for (int i = 0; i < n; i++) {
            Node max;
            int max_ind = -1;
            max = {-1, -1};
            for (int j = 1; j <= 100; j++) {
                if (HeapEmpty(h[j])) {
                    continue;
                }
                Node nowZombie = HeapTop(h[j]);
                nowZombie.dis += i * j;
                if (NodeCmd(nowZombie, max) || max_ind == -1) {
                    max = nowZombie;
                    max_ind = j;
                }
            }
            if (i > 0) {
                cout << " ";
            }
            cout << max.index;
            HeapPop(h[max_ind]);
        }
        cout << endl;

        for (int i = 1; i <= 100; i++) {
            HeapClear(h[i]);
        }
    }
    
    return 0;
}

/* 计蒜客数据结构堆与优先队列练习题：
 * 植物大战僵尸*/
