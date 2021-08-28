/*
 *	 File Name:    binary_tree.cpp
 *	 Author:       sunowsir
 *	 Mail:         sunowsir@protonmail.com
 *	 Created Time: 2018年10月23日 星期二 19时17分34秒
 */

#include <cstdlib>
#include <cstdio>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node *init(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->rchild = p->lchild = NULL;
    return p;
}

Node *build () {
    Node *root = init(1);
    root->lchild = init(2);
    root->rchild = init(3);
    root->lchild->lchild = init(6);
    root->lchild->rchild = init(7);
    root->lchild->lchild->rchild = init(12);
    root->rchild->lchild = init(5);
    root->rchild->rchild = init(9);
    root->rchild->lchild->lchild = init(10);
    root->rchild->lchild->rchild = init(11);
    return root;
}

int height_tree(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int lh = height_tree(root->lchild), rh = height_tree(root->rchild);
    return (lh > rh ? lh : rh) + 1;
}

void preorder(Node *root) {
    if (root == NULL) {
        return ;
    }
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
    printf("\n");
    return ;
}
void inorder(Node *root) {
    if (root == NULL) {
        return ;
    }
    preorder(root->lchild);
    printf("%d ", root->data);
    preorder(root->rchild);
    printf("\n");
    return ;
}
void postorder(Node *root) {
    if (root == NULL) {
        return ;
    }
    preorder(root->lchild);
    preorder(root->rchild);
    printf("%d ", root->data);
    printf("\n");
    return ;
}

void clear(Node *node) {
    if (node == NULL) {
        return ;
    }
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

int main() {
    Node *root = build();
    printf("height(root) = %d\n", height_tree(root));
    preorder(root);
    inorder(root);
    postorder(root);
    return 0;
}
