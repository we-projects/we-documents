/*
 *	 File Name:    queue.c
 *	 Author:       sunowsir
 *	 Mail:         sunowsir@protonmail.com
 *	 Created Time: 2018年10月21日 星期日 18时13分58秒
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n;
    q->data  = (int *)malloc(sizeof(int) * n);
    q->cnt = 0;
    q->head = 0;
    q->tail = -1;
    return q;
}

int push(Queue *q, int value) {
    if (q->cnt == q->length) {
        return 0;
    }
    q->tail += 1;
    if (q->tail >= q->length) {
        q->tail -= q->length;
    }
    q->cnt += 1;
    q->data[q->tail] = value;
    return 1;
}

int empty(Queue *q) {
    return q->cnt == 0;
}

void pop(Queue *q) {
    if (empty(q)) {
        return ;
    }
    q->head += 1;
    if (q->head >= q->length) {
        q->head -= q->length;
    }
    q->cnt -= 1;
    return ;
}

int front(Queue *q) {
    if (empty(q)) {
        return 0;
    }
    return q->data[q->head];
}

void clear(Queue *q) {
    if (q == NULL) {
        return ;
    }
    free(q->data);
    free(q);
}

void output(Queue *q) {
    printf("Queue = [ ");
    for (int i = q->head; i < q-> cnt; i++) {
        int ind = (q->head + i) % q->length;
        printf(" %d", q->data[ind]);
        i + 1 == q->cnt || printf(",");
    }
    printf(" ]\n");
}

int main() {

    #define MAX_OP 20
    Queue *q = init(MAX_OP);
    srand(time(0));
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, value = rand() % 100;
        switch (op) {
            case 0 : 
            case 1 : 
            case 2 : 
                printf("push %d to queue\n", value);
                push(q, value);
                output(q);
                break;
            case 3 : 
                printf("pop %d from queue\n", front(q));
                pop(q);
                output(q);
                break;
        }
    }
    clear(q);

    return 0;
}
