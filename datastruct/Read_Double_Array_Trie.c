/*
 * File Name:    Read_Double_Array_Trie.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月06日 星期日 15时57分02秒
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDAT(int *base, int *check, int ind, char *str, int k) {
    if (check[ind] < 0) {
        printf("%s\n", str);
    }
    for (int i = 0; i < 26; i++) {
        int son_pos, son_check;
        son_pos = base[ind] + i;
        son_check = abs(check[base[ind] + i]);
        if (son_check != ind || son_pos == 1) {
            continue;
        }
        str[k] = 'a' + i;
        str[k + 1] = '\0';
        printDAT(base, check, son_pos, str, k + 1);
    }
    return ;
}

int main() {
    int base[1000], check[1000], ind, base_num, check_num;
    memset(base, 0, sizeof(base));
    memset(base, 0, sizeof(check));
    while (~scanf("%d %d %d", &ind, &base_num, &check_num)) {
        base[ind] = base_num;
        check[ind] = check_num;
    }

    char str[100];
    printDAT(base, check, 1, str, 0);
    
    return 0;
}
