/*
 *	 File Name:    P1054.cpp
 *	 Author:       sunowsir
 *	 Mail:         sunowsir@protonmail.com
 *	 Created Time: 2018年10月21日 星期日 20时05分47秒
 */

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

#define MAX_PRIOR 0x3f3f3f3f
#define MOD_MAX 100000007
#define ll long long 

int calc(char *str, int l, int r, ll var_value) {
    int last_priority, more_priority, pos;
    pos = -1;
    more_priority = 0;
    last_priority = MAX_PRIOR - 1;
    
    // search root 
    for (int i = l; i <= r; i++) {
        int priority = MAX_PRIOR;
        switch (str[i]) {
            case '(' : more_priority += 4; break;
            case ')' : more_priority -= 4; break;
            case '+' : priority = more_priority + 1; break;
            case '-' : priority = more_priority + 1; break;
            case '*' : priority = more_priority + 2; break;
            case '/' : priority = more_priority + 2; break;
            case '^' : priority = more_priority + 3; break;
        }
        if (priority <= last_priority) {
            pos = i;
            last_priority = priority;
        }
    }

    // cout << "find : " << str[pos] << endl;

    /* Judegement and recursion. */
    if (pos == -1) {
        ll ret_num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') {
                if (str[i] != 'a') {
                    continue;
                }
            }
            ll this_num;
            if (str[i] == 'a') {
                this_num = var_value;
            } else {
                this_num = str[i] - '0';
            }
            ret_num = (ret_num * 10 + this_num) % MOD_MAX;
        }
        return ret_num;
    } else {
        /* Perform the corresponding operation
         * based on the operator of the pos position
         * and return the result of the operation. 
         */
        ll num_a = calc(str, l, pos - 1, var_value);
        ll num_b = calc(str, pos + 1, r, var_value);
        switch (str[pos]) {
            case '+' : return (num_a + num_b) % MOD_MAX;
            case '-' : return (num_a - num_b) % MOD_MAX;
            case '*' : return (num_a * num_b) % MOD_MAX;
            case '/' : return (num_a / num_b) % MOD_MAX;
            case '^' : {
                ll temp = 1;
                for (int i = 0; i < num_b; i++) {
                    temp *= num_a;
                    temp %= MOD_MAX;
                }
                return (temp % MOD_MAX);
            }
        }
    }

    return 0;
}

int main() {
    int str_num, str_ans;
    char str[100];
    std::string ans = "";
    memset(str, '\0', sizeof(str));
    scanf("%[^\n]s", str);
    getchar();

    scanf("%d", &str_num);

    str_ans = calc(str, 0, (int)strlen(str), 3);
    // printf("str = %d\n", str_ans);

    for (int i = 0; i < str_num; i++) {
        getchar();
        memset(str, '\0', sizeof(str));
        scanf("%[^\n]s", str);
        
        if (!strcmp(str, "")) {
            i--;
            continue;
        }

        int this_ans = calc(str, 0, (int)strlen(str), 3);
        // printf("\033[1;31m%c \033[0mstr = %d\t", (char)(65 + i), this_ans);
        // printf("this_ans = %d str_ans = %d\n", this_ans, str_ans);
        if (this_ans == str_ans) {
            ans += (char)(65 + i);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
