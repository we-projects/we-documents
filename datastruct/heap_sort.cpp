/* 
 * File Name:    heap_sort.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年10月30日 星期二 20时28分08秒
 */

#include <cstdio>
#include <time.h>
#include <cstdlib>

/* __typeof : 该关键字用来获取一个变量的类型，
* 常用在宏定义中定义与某个已知的变量类型相同的变量。*/
#define swap(a, b) { \
    __typeof(a) __temp = a; a = b; b = __temp; \
}

void heap_sort(int *arr, int n) {
    /* 让指针p指向数组的首位的前一位。
    * 在运算获得某节点的孩子节点时按照从1开始编号运算。*/
    int *p = arr - 1;
    for (int i = n >> 1; i >= 1; i--) {
        int ind = i;
        while ((ind << 1) <= n) {
            int temp = ind;
            if (p[temp] < p[ind << 1]) {
                temp = ind << 1;
            }
            if ((ind << 1 | 1) <= n && p[temp] < p[ind << 1 | 1]) {
                temp = ind << 1 | 1;
            }
            if (temp == ind) {
                break;
            }
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        int ind = 1;
        while ((ind << 1) <= i - 1) {
            int temp = ind;
            if (p[temp] < p[ind << 1]) {
                temp = ind << 1;
            }
            if ((ind << 1 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1]) {
                temp = ind << 1 | 1;
            }
            if (temp == ind) {
                break;
            }
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    return ;
}


void output(int *num, int n) {
    printf("Arr = [");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
        i == n - 1 || printf(",");
    }
    printf("]\n");
    return ;
}
int main() {
    srand(time(0));
    #define MAX_N 20
    int arr[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, MAX_N);
    heap_sort(arr, MAX_N);
    output(arr, MAX_N);
    return 0;
}
