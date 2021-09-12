/*
 * File Name:    Trie_other_build_fail.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月20日 星期日 09时44分29秒
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26
#define BASE 'a'

typedef struct TrieNode {
    int flag;
    struct TrieNode **childs;
    struct TrieNode *fail, *father;
} TrieNode, *Trie;

Trie get_new_node(Trie father) {
    Trie p = (Trie)calloc(sizeof(TrieNode), 1);
    p->childs = (TrieNode **)calloc(sizeof(Trie), SIZE);
    return p;
}

void insert(Trie root, char *str) {
    Trie p = root;
    for (int i = 0; str[i]; i++) {
        if (p->childs[str[i]] - BASE == NULL) {
            p->childs[str[i] - BASE] = get_new_node(p);
        }
        p = p->childs[str[i] - BASE];
    }
    p->flag = 1;
}

void build_ac(Trie root) {
    if (root == NULL) {
        return ;
    }
    if (root->fail == NULL) {
        build_ac(root->father);
    }
    for (int i = 0; i< SIZE; i++) {
        if (root->childs[i] == NULL) {
            continue;
        }
        Trie p = root->fail, pre_p = root;
        while (p != NULL && p->childs[i] == NULL){
            if (p->fail == NULL) {
                build_ac(p->father);
            }
            pre_p = p;
            p = p->fail;
        }
        if (p == NULL) {
            p = pre_p;
        }
        build_ac(root->childs[i]);
    }
    return ;
}

void clear(Trie root) {
    if (root == NULL) {
        return ;
    }
    for (int i = 0; i< SIZE; i++) {
        clear(root->childs[i]);
    }
    free(root->childs);
    free(root);
}

int main() {
    Trie root = get_new_node(NULL);
    return 0;
}


