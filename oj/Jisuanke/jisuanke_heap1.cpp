/* 
 * File Name:    jisuanke_heap1.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年11月02日 星期五 20时03分48秒
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#define swap(a, b) { \
    __typeof(a) __temp; \
    (__temp) = (a); \
    (a) = (b); \
    (b) = (__temp); \
}

using std::cin;
using std::cout;
using std::endl;

/* 建立一个大根堆，然后建立哈弗曼树，每次取最大的建成树，做孩子放两个值较大的 */

typedef struct Heap {
    double *data;
    int size, length;
} Heap;

Heap *Heap_Init(int size) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (double *)malloc(sizeof(double) * size);
    h->size = size;
    h->length = 0;
    return h;
}

bool Heap_Empty(Heap *h) {
    return h->length == 0;
}

void output(Heap *h) {
    printf("Heap = [");
    for (int i = 0; i < h->length; i++) {
        printf("%.4f, ", h->data[i]);
    }
    printf("]\n");
    return ;
}

void Heap_Update(Heap *h, int ind) {
    int max_ind, lchild, rchild;
    max_ind = ind;
    lchild = ind * 2 + 1;
    rchild = ind * 2 + 2;
    if (lchild < h->length && h->data[max_ind] < h->data[lchild]) {
        max_ind = lchild;
    }
    if (rchild < h->length && h->data[max_ind] < h->data[rchild]) {
        max_ind = rchild;
    }
    if (max_ind != ind) {
        swap(h->data[ind], h->data[max_ind]);
        Heap_Update(h, max_ind);
    }
    return ;
}

bool Heap_Push(Heap *h, double data) {
    if (h->length >= h->size) {
        return false;
    }
    int current, father;
    current = h->length;
    father = (current - 1) / 2;
    h->data[h->length] = data;
    h->length++;
    while (h->data[current] > h->data[father]) {
        swap(h->data[current], h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    return true;
}

bool Heap_Pop(Heap *h) {
    if (Heap_Empty(h)) {
        return false;
    }
    h->length--;
    swap(h->data[0], h->data[h->length]);
    Heap_Update(h, 0);
    return true;
}

double Heap_Top(Heap *h) {
    return h->data[0];
}

bool Heap_Haff(Heap *h) {
    if (Heap_Empty(h)) {
        return false;
    }
    while (h->length > 1) {
        double a, b;
        a = Heap_Top(h);
        Heap_Pop(h);
        b = Heap_Top(h);
        Heap_Pop(h);
        Heap_Push(h, pow(a, 1.0 / 3.0) * pow(b, 2.0 / 3.0));
    }
    return true;
}

bool Heap_Clear(Heap *h) {
    if (h == NULL) {
        return false;
    }
    free(h->data);
    free(h);
    return true;
}

int main() {
    int n;
    cin >> n;
    Heap *h = Heap_Init(n * 2 + 5);
    for (int i = 0; i < n; i++) {
        double quality;
        cin >> quality;
        Heap_Push(h, quality);
    }
    Heap_Haff(h);
    printf("%lf\n", Heap_Top(h));
    Heap_Clear(h);
    return 0;
}

/* 计蒜客数据结构习题：
 * 蒜头君的新玩具*/
