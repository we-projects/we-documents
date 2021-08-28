/* 
 * File Name:    priority_queue.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年10月30日 星期二 19时23分55秒
 */

#include <time.h>
#include <cstdio>
#include <cstdlib>

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return 0;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int push(priority_queue *q, int value) {
    if (q->cnt == q->size) {
        return 0;
    }
    q->data[++q->cnt] = value;
    int ind = q->cnt;
    while (ind > 1) {
        /* Jump out of the loop if the new node already meets the rules of Heap.  */
        if (q->data[ind] <= q->data[ind >> 1]) {
            break;
        }
        /* Otherwise(否则) the new Node is exchanged with the parent of the node.  */ 
        swap(q->data[ind], q->data[ind >> 1]);
        /* The Current Node points to the parent node.  */
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (empty(q)) {
        return 0;
    }
    /* Overwrite(覆盖) the head node with the last node.  */
    q->data[1] = q->data[q->cnt--];
    /* Adjust(调整) from top to bottom.  */
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        /* Find the largest node in the parent and son nodes.  */
        int temp = ind;
        if (q->data[temp] < q->data[ind << 1]) {
            temp = ind << 1;
        }
        if ((ind << 1 | 1) <= q->cnt && 
            q->data[temp] < q->data[ind << 1 | 1]) {
            temp = ind << 1 | 1;
        }
        /* Jump out of the loop if the parent node is the largest. */
        /* Otherwise exchange the largest node to the parent node and update 'ind'. */
        if (temp == ind) {
            break;
        } else {
            swap(q->data[ind], q->data[temp]);
            ind = temp;
        }
    }
    return 1;
}

int top(priority_queue *q) {
    return q->data[1];
}

void clear(priority_queue *q) {
    if (q == NULL) {
        return ;
    }
    free(q->data);
    free(q);
    return ;
}

void output(priority_queue *q) {
    printf("Queue = [");
    for (int i = 1; i <= q->cnt; i++) {
        printf(" %d", q->data[i]);
        i == q->cnt || printf(",");
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    priority_queue *q = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 1, value = rand() % 100;
        switch (op) {
            case 0 :
            case 1 :
            case 2 :
                printf("push %d to priority_queue\n", value);
                push(q, value);
                break;
            case 3 : 
                printf("pop %d from priority_queue\n", top(q));
                pop(q);
                break;
        }
        output(q);
        
    }
    

    return 0;
}

/* 海贼数据结构课，优先队列现场代码。  */
