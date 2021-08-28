/*
 * File Name:    binary_search_tree.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月20日 星期日 18时55分01秒
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->key = key;
    return p;
}

Node *insert(Node *root, int key) {
    if (root = NULL) {
        return getNewNode(key);
    }
    if (root->key == key) {
        return root;
    }
    if (root->key > key) {
        root->lchild = insert(root->lchild, key);
    } else {
        root->rchild = insert(root->rchild, key);
    }
    return root;
}

Node *predecessor(Node *node) {
    Node *temp = node->lchild;
    while (temp->rchild) {
        temp = temp->rchild;
    }
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (root->key < key) {
        root->rchild = erase(root->rchild, key);
    } else if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else {
        /* 度为0的节点（叶子节点）  */
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            root == NULL;
        } else if (root->lchild == NULL || root->rchild == NULL) {
            /* 度为1的节点 ，把非空的子节点返回给父节点*/
            Node *temp = (root->lchild ? root->lchild : root->rchild);
            free(root);
            return temp;
        } else {
            /* 度为2的节点 ，*/
            /* 获取当前节点的前驱节点  */
            Node *temp = predecessor(root);
            /* 将前驱节点的值给当前节点  */
            root->key = temp->key;
            /* 将前驱节点删除  */
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

int search(Node *root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->key == key) {
        return 1;
    }
    return ((root->key > key ? search(root->lchild, key) : search(root->rchild, key)));
}

void clear(Node *node) {
    if (node == NULL) {
        return ;
    }
    clear(node->lchild);
    clear(node->rchild);
    clear(node);
    return ;
}

void output(Node *root) {
    if (root == NULL) {
        return ;
    }
    output(root->lchild);
    printf("%d ", root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    Node *root = NULL;
    int op, val;
    #define MAX_OP 20
    #define MAX_N 15
    for (int i = 0; i< MAX_OP; i++) {
        op = rand() % 6;
        val = rand() % MAX_N;
        switch (op) {
            case 0 : {
                printf("search 5d = %d\n", val, search(root, val));
            } break;
            case 1 : {
                printf("erase %d from BST\n", val);
                root = erase(root, val);
            } break;
            default : {
                printf("insert %d to BST\n", val);
                root = insert(root, val);
            } break;
            output(root);
            printf("\n");
        }
    }
    #undef MAX_OP
    #undef MAX_N
    return 0;
}
