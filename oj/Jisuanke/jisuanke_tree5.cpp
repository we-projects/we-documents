/* 
 * File Name:    jisuanke_tree5.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年10月29日 星期一 17时11分47秒
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void output(Node *root) {
    if (root == NULL) {
        return ;
    }
    printf("%c", root->data);
    if (root->lchild != NULL || root->rchild != NULL) {
        printf("(");
    }
    output(root->lchild);
    if (root->rchild != NULL) {
        printf(",");
    }
    output(root->rchild);
    if (root->lchild != NULL || root->rchild != NULL) {
        printf(")");
    }
}

Node *search(Node *root, char sstr) {
    if (root == NULL) {
        return NULL;
    }
    // printf("root->data : %c\n", root->data);
    if (root->data == sstr) {
        return root;
    }
    Node *l = search(root->lchild, sstr); 
    Node *r = search(root->rchild, sstr);
    return (l != NULL ? l : r);
}

Node *buildTree(Node *root, char *str) {
    if (str[0] == '^') {
        if (str[1] != '^') {
            root = getNewNode(str[1]);
        }
        return root;
    }
    Node *father = search(root, str[0]);
    if (father == NULL) {
        return root;
    }
    if (str[2] == 'L') {
        father->lchild = getNewNode(str[1]);
    } else if (str[2] == 'R'){
        father->rchild = getNewNode(str[1]);
    }
    return root;
}

bool clearTree(Node *root) {
    if (root == NULL) {
        return false;
    }
    clearTree(root->lchild);
    clearTree(root->rchild);
    free(root);
    return true;
}

int main () {
    char str[4] = {'\0'};
    Node *root = NULL;
    while(str[1] != '^') {
        scanf("%s", str);
        root = buildTree(root, str);
    }
    output(root);
    printf("\n");
    clearTree(root);
    return 0;
}
