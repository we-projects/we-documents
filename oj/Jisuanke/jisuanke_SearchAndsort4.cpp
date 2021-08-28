/*
* File Name: jisuanke_SearchAndsort4.cpp
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月07日 星期三 12时27分43秒
*/

#include <cstdio>
#include <algorithm>

typedef struct Node {
    int ind, value;
} Node;

int binarySearch(Node *num, int searchNum, int l, int r) {
    int head, tail;
    head = l;
    tail = r;
    while (head <= tail) {
        int mid = (head + tail) >> 1;
        if (searchNum == num[mid].value) {
            return mid;
        } else if (searchNum < num[mid].value) {
            tail = mid - 1;
        } else {
            head = mid + 1;
        }
    }
    return -1;
}

void quick_sort(Node *num, int l, int r) {
    if (r <= l) {
        return ;
    }
    int leftInd, rightInd;
    Node midNum;
    leftInd = l;
    rightInd = r;
    midNum = num[leftInd];
    while (leftInd < rightInd) {
        while (leftInd < rightInd && num[rightInd].value >= midNum.value) {
            rightInd--;
        }
        if (leftInd < rightInd) {
            num[leftInd++] = num[rightInd];
        }
        while (leftInd < rightInd && num[leftInd].value <= midNum.value) {
            leftInd++;
        }
        if (leftInd < rightInd) {
            num[rightInd--] = num[leftInd];
        }
    }
    num[leftInd] = midNum;
    quick_sort(num, l, leftInd - 1);
    quick_sort(num, leftInd + 1, r);
    return ;
}

bool cmd(Node a, Node b) {
    return (a.value == b.value ? a.ind < b.ind : a.value < b.value);
}

int main() {
    int n;
    scanf("%d", &n);
    Node num[n << 1] = {0, 0};
    for (int i = 0; i < n; i++) {
        num[i].ind = i + 1;
        scanf("%d", &num[i].value);
    }
    int target;
    int ind1, ind2;
    ind1 = -1;
    ind2 = -1;
    scanf("%d", &target);
    std::sort(num, num + n, cmd);
    //quick_sort(num, 0, n - 1);
    for (int i = 0; i < n; i++) {
        ind2 = binarySearch(num, target - num[i].value, i, n - 1);
        if (ind2 != -1) {
            ind1 = num[i].ind;
            ind2 = num[ind2].ind;
            break;
        }
    }
    if (ind2 != -1) {
        int minInd = (ind1 < ind2 ? ind1 : ind2);
        int maxInd = (ind1 > ind2 ? ind1 : ind2);
        printf("%d %d\n", minInd, maxInd);
    }
    
    return 0;
}

/* 计蒜客数据结构哈希查找与排序的复习：两数之和 */
