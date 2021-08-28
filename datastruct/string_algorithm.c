/*
 * File Name:    string_algorithm.c
 * Author:       sunowsir (copy from hug@haizei)
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月30日 星期日 19时43分32秒
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEST(func, a, b) { \
    printf("%s(\"%s\", \"%s\") = %d\n", #func, a, b, func(a, b)); \
}

int BruteForce(char *str, char *pattern) {
    for (int i = 0; str[i]; i++) {
        int flag = 1;
        for (int j = 0; pattern[j]; j++) {
            if (str[i + j] == pattern[j]) {
                continue;
            }
            flag = 0;
            break;
        }
        if (flag) {
        return i;
        }
    }
    return -1;
    
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * (int)strlen(pattern));
    next[0] = -1;
    
    /* 生成模式串的next数组 */
    for (int i = 1; pattern[i]; i++) {
        /* j : i位置的字符的前一个字符上一次出现的位置 */
        int j = next[i - 1]; 
        /* 如果j位置的字符不是第一次出现，
        *  并且j后面的位置不是i位置字符上一次出现的位置
        *  那么继续往前找j位置字符上一次出现的位置 
        *  直到j指向了该位置字符第一次出现的位置，
        *  或者j + 1位置是ｉ位置字符上一次出现的位置*/
        while (j != -1 && pattern[j + 1] != pattern[i]) {
            j = next[j];
        }
        /* 如果如上的循环跳出是因为j + 1位置是ｉ位置字符上一次出现的位置  
        *  那么将j + 1存储在next[i]中，这样next[i]就指向了i位置字符上一次出现的位置
        *  否则说明ｉ位置的字符是第一次出现在模式串中*/
        if (pattern[j + 1] == pattern[i]) {
            next[i] = j + 1;
        } else {
            next[i] = -1;
        }
    }
    
    /* 开始匹配，ｉ指向母串，ｊ指向模式串 */
    int i = 0, j = -1;
    while (str[i]) {
        while (j != -1 && str[i] != pattern[j + 1]) {
            j = next[j];
        } 
        /* 母串的i位置字符与模式串j + 1位置字符匹配成功 */
        if (str[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if (pattern[j + 1] == 0) {
            return (i - (int)strlen(pattern));
        }
    }
    
    return -1;
}

int Sunday(char *str, char *pattern) {
    #define BASE 128
    int ind[BASE] = {0};
    int len = (int)strlen(pattern);
    int max_len = (int)strlen(str);
    for (int i = 0; i < BASE; i++) {
        ind[i] = len + 1;
    }
    for (int i = 0; i < len; i++) {
        ind[pattern[i]] = len - i;
    }
    for (int i = 0; i < max_len;) {
        int flag = 1;
        for (int j = 0; j < len; j++) {
            if (str[i + j] == pattern[j]) {
                continue;
            }
            i += ind[str[i + len]];
            flag = 0;
            break;
        }
        if (flag) {
            return i;
        }
    }
    return -1;
    #undef BASE
}

int ShiftAnd(char *str, char *pattern) {
    #define BASE 128
    int code[BASE] = {0};
    int len = 0;
    for (len = 0; pattern[len]; len++) {
        code[pattern[len]] |= (1 << len);
    }
    int p = 0;
    for (int i = 0; str[i]; i++) {
        p = (p << 1 | 1) & code[str[i]];
        if (p & (1 << (len - 1))) {
            return (i - len + 1);
        }
    }
    return -1;
    #undef BASE
}

int main() {
    char str[100], pattern[30];
    while (scanf("%s%s", str, pattern) != EOF) {
        TEST(BruteForce, str, pattern);
        TEST(KMP, str, pattern);
        TEST(Sunday, str, pattern);
        TEST(ShiftAnd, str, pattern);
    }
    return 0;
}




