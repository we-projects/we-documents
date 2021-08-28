/*
* File Name: jisuanke_SearchAndsort2.cpp
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月07日 星期三 10时29分41秒
*/

#include <cstdio>

int binarySearch(int *num, int n, int searchNum) {
    int head, tail;
    head = 0;
    tail = n - 1;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (searchNum < num[mid]) {
            tail = mid - 1;
        } else {
            head = mid;
        }
    }
    return head;
}

void quick_sort(int *num, int l, int r) {
    if (r <= l) {
        return ;
    }
    int left, right, mid;
    left = l;
    right = r;
    mid = num[l];
    while (left < right) {
        while (left < right && num[right] >= mid){
            right--;
        }
        if (left < right) {
            num[left++] = num[right];
        }
        while (left < right && num[left] <= mid) {
            left++;
        }
        if (left < right) {
            num[right--] = num[left];
        }
    }
    num[left] = mid;
    quick_sort(num, l, left - 1);
    quick_sort(num, left + 1, r);
    return ;
}

int main() {
    int searchNum, n, m;
    scanf("%d%d", &n, &m);
    int num[n + 5] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    quick_sort(num, 0, n - 1);
    for (int i = 0; i < m; i++) {
        scanf("%d", &searchNum);
        if (i > 0) {
            printf(" ");
        }
        int ansInd = binarySearch(num, n, searchNum);
        printf("%d", num[ansInd]);
    }
    printf("\n");
    return 0;
}


/* 计蒜客数据结构，排序与查找的复习：报数游戏，新报数游戏 */
