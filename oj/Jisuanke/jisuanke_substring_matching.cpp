/*
 * File Name:    jisuanke_substring_matching.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月17日 星期四 18时53分52秒
 */

#include <cstdio>
#include <cstring>

int StrtoInt(char *str, int *end_pos) {
    int ans = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            *end_pos = i - 1;
            break;
        }
        ans = ans * 10 + (str[i] - '0');
    }
    return ans;
}

int main() {
    char stra[1010] = {0}, strb[110] = {0};
    scanf("%s %s", stra, strb);
    int cycle_start, strb_pos, strb_len, sub_num, flag, cycle_num, end_pos;
    flag = 0;
    end_pos = 0;
    sub_num = 0;
    strb_pos = 0;
    cycle_num = 0;
    cycle_start = -1;
    strb_len = (int)strlen(strb);
    for (int i = 0; stra[i];) {
        if (stra[i] == '[') {
            cycle_start = i++;
        } else if (stra[i] == ']') {
            if (!flag) {
                flag = 1;
                cycle_num = StrtoInt(&stra[i + 1], &end_pos);;
                end_pos += i + 2;
            }
            // printf(" <cycle_num = %d> \n", cycle_num);
            if (cycle_num > 1) {
                cycle_num--;
                i = cycle_start;
            } else {
                flag = 0;
                i = end_pos + 1;
            }
            
        } else {
            // printf("%c", stra[i]);
            bool same_len = (strb_pos == strb_len - 1 ? true : false);
            bool same_char = (stra[i] == strb[strb_pos] ? true : false);
            
            if (same_len) {
                if (same_char) {
                    sub_num++;
                }
                strb_pos = 0;
            } else {
                if (same_char) {
                    strb_pos++;
                } else {
                    strb_pos = 0;
                }
            }
            
            i++;
        } 
    }
    // printf("\n");
    printf("%d\n", sub_num);
    
    return 0;
}

/* 计蒜客数据结构习题：子串匹配  */
