/* 
 * File Name:    haffman.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年10月28日 星期日 20时01分50秒
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cinttypes>

typedef struct Node {
    char key;
    int freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

bool clear(Node *root) {
    if (root == NULL){
        return false;
    }
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return true;
}

void swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return ;
}

Node *build_haffman(Node **arr, int n) {
    Node INIT_NODE = {0, INT32_MAX, NULL, NULL};
    while (n > 1){
        Node *first, *second = &INIT_NODE;
        int first_pos, second_pos;
        first = &INIT_NODE;
        second = &INIT_NODE;
        first_pos = 0;
        second_pos = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j]->freq < first->freq) {
                second = first;
                second_pos = first_pos;
                first = arr[j];
                first_pos = j;
            } else if (arr[j]->freq < second->freq) {
                second = arr[j];
                second_pos = j;
            }
        }

        Node *temp = getNewNode(0, first->freq + second->freq);
        temp->lchild = first;
        temp->rchild = second;
        if (arr[n - 1] == second) {
            second_pos = first_pos;
        } 
        swap_node(&arr[n - 1], &arr[first_pos]);
        swap_node(&arr[n - 2], &arr[second_pos]);
        arr[n - 2] = temp;
        n--;
    }
    return arr[0];
}

void output(Node *root) {
    if (root == NULL) {
        return ;
    }
    printf("%d", root->freq);
    if (root->lchild != NULL && root->rchild != NULL) {
        printf("(");
    }
    output(root->lchild);
    if (root->rchild != NULL) {
        printf(",");
    }
    output(root->rchild);
    if (root->lchild != NULL && root->rchild != NULL) {
        printf(")");
    }
    return ;
}

void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
    return ;
}

int main () {
    int n,freq;
    char key, code[256][20] = {0}, buff[20];
    Node **arr, *root;
    scanf("%d", &n);
    root = NULL;
    getchar();
    arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++){
        scanf("%c%d", &key, &freq);
        arr[i] = getNewNode(key, freq);
        getchar();
    }
    root = build_haffman(arr, n);

    output(root);
    printf("\n");

    extract_code(root, code, 0, buff);
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0){
            continue;
        }
        printf("%c : %s\n", i, code[i]);
    }
    clear(root);
    free(arr);
    return 0;
}
