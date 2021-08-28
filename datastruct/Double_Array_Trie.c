/*
 * File Name:    Double_Array_Trie.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月06日 星期日 15时15分31秒
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int flag;
    struct Node *next[26];
} Node;

typedef struct DATNode {
    /* base : 当前节点的第一个非空子节点编号，
    *  check ：当前节点的父亲节点，
    *  若当前节点为独立成词的最后一个字母，那么当前节点的check为负*/
    int base, check;
} DATNode;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - 'a'] == NULL) {
            p->next[str[i] - 'a'] = getNewNode();
            cnt += 1;
        }
        p = p->next[str[i] - 'a'];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) {
        return ;
    }
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int getBase(Node *node, DATNode *trie) {
    /* 第一个非空子节点的编号即base  */
    int base, flag;
    base = 1;
    flag = 0;
    while (!flag) {
        flag = 1;
        base += 1;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == NULL) {
                continue;
            }
            if (trie[base + i].check == 0) {
                continue;
            }
            flag = 0;
            break;
        }
    }
    return base;
}

void Transform(Node *node, DATNode *trie, int ind) {
    /* 独立成词check记为负 */
    if (node->flag) {
        trie[ind].check = -trie[ind].check;
    }
    trie[ind].base = getBase(node, trie);
    /* 确定当前节点的每个非空子节点的check */
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) {
            continue;
        }
        /* ind节点，base值 + i  */
        trie[trie[ind].base + i].check == ind;
    }
    /* 递归向下确定子树 */
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) {
            continue;
        }
        Transform(node->next[i], trie, trie[ind].base + i);
    }
    return ;
}

int search(DATNode *trie, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        int delta = str[i] - 'a';
        int check = abs(trie[trie[p].base + delta].check);
        if (check - p) {
            return 0;
        }
        p = trie[p].base + delta;
    }
    return (trie[p].check < 0);
}

int main() {
    int n, cnt = 1;
    char str[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt * 10);
    Transform(root, trie, 1);
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", str, search(trie, str));
    }
    
    clear(root);
    return 0;
}
