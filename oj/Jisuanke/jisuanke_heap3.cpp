/* 
 * File Name:    jisuanke_heap3.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年11月02日 星期五 10时29分39秒
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define swap(a, b) { \
    __typeof(a) __temp; \
    __temp = (a); \
    (a) = (b); \
    (b) = __temp; \
}

typedef struct Node {
    int loc, dis;
} Node;

typedef struct Heap {
    Node *data;
    int size, length;
} Heap;

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

bool HeapCmd(Node a, Node b) {
    if (a.loc == b.loc) {
        return a.dis < b.dis;
    }
    return a.loc < b.loc;
}

bool HeapPush(Heap *h, Node data) {
    if (h->length >= h->size) {
        return false;
    }
    h->data[h->length] = data;
    int current, father;
    current = h->length;
    father = (current - 1) / 2;
    h->length++;
    while (HeapCmd(h->data[current], h->data[father])) {
        swap(h->data[current], h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    return true;
}

void HeapUpdate(Heap *h, int pos) {
    int min_loc, lchild, rchild;
    min_loc = pos;
    lchild = pos * 2 + 1;
    rchild = pos * 2 + 2;
    if (lchild < h->length && !HeapCmd(h->data[min_loc], h->data[lchild])) {
        min_loc = lchild;
    }
    if (rchild < h->length && !HeapCmd(h->data[min_loc], h->data[rchild])) {
        min_loc = rchild;
    }
    if (min_loc != pos) {
        swap(h->data[min_loc], h->data[pos]);
        HeapUpdate(h, min_loc);
    }
    return ;
}

bool pop(Heap *h) {
    if (HeapEmpty(h)) {
        return false;
    }
    h->length--;
    swap(h->data[0], h->data[h->length]);
    HeapUpdate(h, 0);
    return true;
}

Node top(Heap *h) {
    return h->data[0];
}

void output(Heap *h) {
    printf("Heap = [");
    for (int i = 0; i < h->length; i++) {
        printf("(%d,%d), ", h->data[i].loc, h->data[i].dis);
    }
    printf("]\n");
    return ;
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
    while (t--) {
        int n;
        cin >> n;
        Heap *h = init(n + 5);
        for (int i = 0; i < n; i++) {
            Node input;
            cin >> input.loc >> input.dis;
            HeapPush(h, input);
        }
        // printf("TEST : ");
        // output(h);
        int max_dis, num;
        num = 1;
        while (!HeapEmpty(h)) {
            Node nowNode = top(h);
            pop(h);
            max_dis = nowNode.loc;
            if (num % 2) {
                nowNode.loc += nowNode.dis;
                HeapPush(h, nowNode);
            }
            num++;
        }
        cout << max_dis << endl;
        HeapClear(h);
    }
    return 0;
}
