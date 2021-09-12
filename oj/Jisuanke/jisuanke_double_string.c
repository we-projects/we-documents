/*
 * File Name:    KMP.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月16日 星期三 20时30分18秒
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KMP(char *buffer, char *pattern) {
    int *next = (int *)calloc(sizeof(int), (int)strlen(pattern));
    next[0] = -1;
    
    for (int i = 1; pattern[i]; i++) {
        int match = next[i - 1];
        while (match != -1 && pattern[match + 1] != pattern[i]) {
            match = next[match];
        }
        if (pattern[match + 1] == pattern[i]) {
            next[i] = match + 1;
        } else {
            next[i] = -1;
        }
    }

    int match = -1;
    for (int i = 0; buffer[i]; i++) {
        while (match != -1 && pattern[match + 1] != buffer[i]) {
            match = next[match];
        }
        if (pattern[match + 1] == buffer[i]) {
            match++;
        }
        if (match == (int)strlen(pattern) - 1) {
            free(next);
            return i - match;
        }
    }
    free(next);
    return -1;
}


int main() {
    char str1[1000010], str2[1000010], pattern[1010];
    
    scanf("%[^\n]s", str1);
    getchar();
    scanf("%[^\n]s", str2);
    getchar();
    scanf("%[^\n]s", pattern);
    getchar();
    
    int p_len, same_len, start_pos, i;
    p_len = (int)strlen(pattern);
    same_len = 0;
    start_pos = -1;
    for (i = 0; str1[i] || str2[i]; i++) {
        if (str1[i] != str2[i] && same_len != 0) {
            start_pos = i - same_len;
            char temp = str1[i];
            str1[i] = '\0';
            int ret_pos = KMP(&str1[start_pos], pattern);
            str1[i] = temp;
            if (ret_pos != -1) {
                start_pos += ret_pos;
                break;
            } else {
                start_pos = -1;
                same_len = 0;
            }
        } else if (str1[i] == str2[i]){
            same_len++;
        }
    }
    if (same_len != 0) {
        start_pos = i - same_len;
        start_pos += KMP(&str1[start_pos], pattern);
    }
    printf("%d\n", start_pos + 1);

    return 0;
}

/* 计蒜客数据结构课程习题：双串匹配  */
