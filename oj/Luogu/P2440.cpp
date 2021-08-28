/*
* File Name: P2440.cpp
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月08日 星期四 23时13分57秒
*/

#include <cstdio>
#include <cstdlib>
#include <inttypes.h>

int64_t Check(int64_t *num, int64_t n, int64_t every) {
    int64_t ret = 0;
    for (int64_t i = 0; i < n; i++) {
        ret += num[i] / every;
    }
    return ret;
}

int64_t binarySearch(int64_t *num, int64_t k, int64_t n, int64_t maxWood) {
    int64_t head, tail;
    head = 1;
    tail = maxWood;
    while (head < tail) {
        int64_t mid, nums;
        mid = (head + tail + 1) >> 1;
        nums = Check(num, n, mid);
        // printf("%" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 "\n", head, tail, mid, nums);
        if (nums >= k ) {
            head = mid;
        } else {
            tail = mid - 1;
        }
    }
    // printf("head = %" PRId64 " Check(head) = %" PRId64 " k = %" PRId64"\n", head, Check(num, n, head), k);
    return (Check(num, n, head) >= k ? head : -1);
}

int main() {
    int64_t wood[100010], n, k, maxWood;
    maxWood = -1;
    scanf("%" PRId64 "%" PRId64, &n, &k);
    for (int64_t i = 0; i < n; i++) {
        scanf("%" PRId64, &wood[i]);
        maxWood = (maxWood < wood[i] ? wood[i] : maxWood);
    }
    int64_t ans = binarySearch(wood, k, n, maxWood);
    if (ans != -1) {
        printf("%" PRId64  "\n", ans);
    } else {
        printf("0\n");
    }

    return 0;
}
