/*
* File Name: binary_search.cpp
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月06日 星期二 19时27分06秒
*/

#include <cstdio>

/* eg. 1, 2, 3, 4, 5 */
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) {
            return mid;
        }
        if (num[mid] > x) {
            tail = mid - 1;
        }
        else {
            head = mid += 1;
        }
    }
    return -1;
}

/* eg. 1, 1, 1, 1, 1, 0, 0, 0, 0, 0. search the last '1' in the array.*/
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) {
            head = mid;
        } else {
            tail = mid - 1;
        }
    }
    return head;
}

/* eg. 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 . search the first '1' in the array*/
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) {
            tail = mid;
        }
        else {
            head = mid + 1;
        }
    }
    return head == n ? -1 : head;
}


int main() {
    int num1[10] = {9, 7, 5, 3, 1, 2, 4, 6 ,8, 10};
    int num2[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    int num3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    printf("binary_search1(num1) : %d\n", binary_search1(num1, 10, 2));
    printf("binary_search2(num2) : %d\n", binary_search2(num2, 10));
    printf("binary_search3(num3) : %d\n", binary_search3(num3, 10));
    
    return 0;
}
