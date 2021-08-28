/*************************************************************************
	> File Name:    Linklist.cpp
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年10月11日 星期四 23时14分56秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *init() {
    LinkList *new_list = (LinkList *)malloc(sizeof(LinkList));
    new_list->head.next = NULL;
    new_list->length = 0;
    return new_list;
}

LinkNode *getNewNode(int value) {
    LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void insert(LinkList *l, int value, int index) {
    LinkNode *temp_node = &(l->head);
    while (index--) {
        temp_node = temp_node->next;
        if (temp_node == NULL) {
            return ;
        }
    }
    LinkNode *insert_node = getNewNode(value);
    insert_node->next = temp_node->next;
    temp_node->next = insert_node;
    l->length++;
    return ;
}

void erase(LinkList *l, int index) {
    LinkNode *temp_node = &(l->head);
    while(index--) {
        temp_node = temp_node->next;
        if (temp_node == NULL) {
            return ;
        }
    }
    if (temp_node->next == NULL) {
        return ;
    } 
    LinkNode *delete_node = temp_node->next;
    temp_node->next = temp_node->next->next;
    free(delete_node);
    l->length--;
    return ;
}

void output(LinkList *l) {
    printf("[%d]", l->length);
    LinkNode *output_node = l->head.next;
    while (output_node != NULL) {
        printf(" %d -> ", output_node->data);
        output_node = output_node->next;
    }
    printf(" NULL\n");
    return ;
}

void clear(LinkList *l) {
    if (l->length == 0) {
        return ;
    }
    LinkNode *now_node = l->head.next, *delete_node;
    while(now_node != NULL) {
        delete_node = now_node;
        now_node = now_node->next;
        free(delete_node);
    }
    free(l);

    return ;
}

int main() {
    srand(time(0));
    LinkList *l = init();
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, value, ind;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                ind = rand() % (l->length + 1);
                value = rand() % 100;
                printf("insert(%d, %d) to LinkList\n", value, ind);
                insert(l, value, ind);
                output(l);
            } break;
            case 3: {
                if (l->length == 0) break;
                ind = rand() % l->length;
                printf("erase(%d) from LinkList\n", ind);
                erase(l, ind);
                output(l);
            } break;
        }
    }
    clear(l); 
    return 0;
}
