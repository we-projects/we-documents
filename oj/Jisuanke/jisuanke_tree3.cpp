/* 
 * File Name:    jisuanke_tree3.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年10月27日 星期六 19时09分21秒
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

Node *init(char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Node *build(char *str, int pos) {
    int len = (int)strlen(str);
    if (len == 0){
        return NULL;
    }
    Node *node = init(str[pos]);
    if ((pos + 1) * 2 <= len) {
        node->lchild = build(str, (pos + 1) * 2 - 1);
    }
    if ((pos + 1) * 2 + 1 <= len) {
        node->rchild = build(str, (pos + 1) * 2);
    }
    return node;
}

void output(Node *root) {
    if (root == NULL) {
        return ;
    }
    printf("%c", root->data);
    if (root->lchild != NULL || root->rchild != NULL){
        printf("(");
    }
    output(root->lchild);
    if (root->rchild != NULL) {
        printf(",");
    }
    output(root->rchild);
    if (root->lchild != NULL || root->rchild != NULL){
        printf(")");
    }
    return ;
}

void clear(Node *root) {
    if (root == NULL) {
        return ;
    }
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
    char str[10010] = {'\0'}, input;
    int len = 0;
    input = '\0';
    while (input != '$') {
        scanf("%c", &input);
       	if (input != ' ') {
            str[len++] = input;
        }
    }
    str[len - 1] = '\0';

    if (len == 0) {
        cout << "" << endl;
    }
    Node *root = build(str, 0);
    output(root);
    printf("\n");
    clear(root);
    return 0;
}
