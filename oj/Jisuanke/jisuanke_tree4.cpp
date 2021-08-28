/* 
 * File Name:    jisuanke_tree4.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年10月27日 星期六 19时38分13秒
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

typedef struct Stack {
    struct Node **node;
    int top, size;
} Stack;

typedef struct Queue {
    struct Node **node;
    int cnt, head, tail, length;
} Queue;

Queue *initQueue(int length) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->node = (Node **)malloc(sizeof(Node *) * length);
    q->cnt = 0;
    q->head = 0;
    q->tail = -1;
    q->length = length;
    return q;
}

bool empty(Queue *q) {
    return q->cnt == 0;
}

bool push(Queue *q, Node *node) {
    if (q->cnt >= q->length) {
        return false;
    }
    q->cnt += 1;
    q->tail += 1;
    if (q->tail >= q->length) {
        q->tail -= q->length;
    }
    q->node[q->tail] = node;
    return true;
}

bool pop(Queue *q) {
    if (empty(q)) {
        return false;
    }
    q->cnt -= 1;
    q->head += 1;
    if (q->head >= q->length) {
        q->head -= q->length;
    }
    return true;
}

Node *front(Queue *q) {
    if (empty(q)) {
        return NULL;
    }
    return q->node[q->head];
}

bool clearQueue(Queue *q) {
    if (q == NULL) {
        return false;
    }
    free(q->node);
    free(q);
    return true;
}

Stack *initStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->node = (Node **)malloc(sizeof(Node *) * size);
    s->top = -1;
    s->size = size;
    return s;
}

bool clearStack(Stack *s) {
    if (s == NULL) {
        return false;
    }
    free(s->node);
    free(s);
    return NULL;
}

bool empty(Stack *s) {
    return s->node == NULL || s->top == -1;
}

Node *top(Stack *s) {
    if (empty(s)) {
        return NULL;
    }
    return s->node[s->top];
}

bool push(Stack *s, Node *node) {
    if (s->top + 1 >= s->size) {
        return false;
    }
    s->top += 1;
    s->node[s->top] = node;
    return true;
}

bool pop(Stack *s) {
    if (empty(s)) {
        return false;
    }
    s->top -= 1;
    return true;
}

Node *getNewNode (char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Node *build (char *str) {
    Stack *s = initStack(1000);
    Node *node, *root;
    int flag;
    flag = 0;
    node = NULL;
    root = NULL;
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case '(' : {
                push(s, node);
                flag = 0;
            } break;
            case ')' : {
                pop(s);
            } break;
            case ',' : {
                flag = 1;
            } break;
            case ' ' : break;
            default : {
                /* 建立新节点 */
                node = getNewNode(str[i]);
                /* 若root为空，说明当前节点为根节点 */
                if (root == NULL) {
                    root = node;
                }
                /* 若栈为空说明该节点不是任何节点的儿子，
                * 也就是说他是根节点*/
                if (empty(s)) {
                    break;
                }
                /* 若栈不为空，说明该节点是栈顶元素的儿子节点，
                * 根据flag来判断是哪个儿子*/
                if (flag == 0) {
                    top(s)->lchild = node;
                } else {
                    top(s)->rchild = node;
                }
            }
        }
    }
    clearStack(s);
    return root;
}

void output(Node *root, char first) {
    if (root == NULL) {
        return ;
    }
    Queue *que = initQueue(1000);
    push(que, root);

    while (!empty(que)) {
        Node *nowNode = front(que);
        if (nowNode->data != first) {
            printf(" ");
        }
        printf("%c", nowNode->data);
        pop(que);
        if (nowNode->lchild != NULL) {
            push(que, nowNode->lchild);
        }
        if (nowNode->rchild != NULL) {
            push(que, nowNode->rchild);
        }
    }
    printf("\n");

    return ;
}

void clearTree(Node *root) {
    if(root == NULL) {
        return ;
    }
    clearTree(root->lchild);
    clearTree(root->rchild);
    free(root);
    return ;
}

int main () {

    char str[10010] = {'\0'};
    scanf("%[^\n]s", str);
    if ((int)strlen(str) == 0) {
        cout << "" << endl;
        return 0;
    }
    Node *root = build(str);
    output(root, str[0]);

    clearTree(root);
    return 0;
}
