/*************************************************************************
	> File Name: 12.ac.cpp
	> Author: ldc
	> Mail: litesla
	> Created Time: 2018年12月06日 星期四 17时01分12秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BASE 26
#define BL 'a'

typedef struct Node{
    int flag;
    char *str;
    struct Node *fail;
    struct Node *next[BASE];
}Node;

Node *get_new_node(){
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}
void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    if (root->str != NULL) free(root->str);
    free(root);
    return ;
}

Node* insert(Node *root, const char *str) {
    if (root == NULL) root = get_new_node();
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BL] == NULL) p->next[str[i] - BL] = get_new_node();
        p = p->next[str[i] - BL];
    }
    p->flag = 1;
    p->str = strdup(str);
    return root;
}
void build_ac(Node *root){
    #define max_n 1000
    if (root == NULL) return ;
    Node **queue = (Node **)malloc(sizeof(Node *) * max_n);
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        Node *node = queue[head++];
        for (int i = 0; i < BASE; i++) {
            if (node->next[i] == NULL) continue;
            Node *p = node->fail;
            while (p && p->next[i] == NULL) p = p->fail;
            if (p == NULL) node->next[i]->fail = root;
            else node->next[i]->fail = p->next[i];
            queue[tail++] = node->next[i];
        }
    }
    return ;
}

void  search_ac(Node *root, const char *text) {
    if (root == NULL) return ;
    Node *p = root;
    for (int i = 0; text[i]; i++) {
        while (p && p->next[text[i] - BL] == NULL)  p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[text[i] - BL];
        Node *q = p;
        while (q) {
            if (q->flag) printf("find word :%s\n", q->str);
            q = q->fail;
        }
    }
}


int main(){
    Node *root = NULL;
    root = insert(root, "say");
    root = insert(root, "she");
    root = insert(root, "shr");
    root = insert(root, "he");
    root = insert(root, "her");
    build_ac(root);
    search_ac(root,"sasherhs");
    clear(root);
    return 0;
}
