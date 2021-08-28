/*
 * File Name:    jisuanke_string_count.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月17日 星期四 12时06分50秒
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

#define BASE 'a'
#define SIZE 26
#define MAX_LEN 100005 
#define MAX_NUM 1005

typedef struct TrieNode {
    int count, flag[100];
    struct TrieNode **childs;
    struct TrieNode *fail;
} TrieNode, *Trie;

Trie get_new_node();

void insert(Trie, char *, int);

void build_fail(Trie);

int match(Trie, char *, int *);

void clear(Trie);

int main() {
    int n;
    Trie root = get_new_node();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char pattern[25] = {0};
        scanf("%s", pattern);
        insert(root, pattern, i);
    }
    build_fail(root);
    char buffer[MAX_LEN] = {0};
    scanf("%s", buffer);
    int ans[n] = {0};
    int total_count = match(root, buffer, ans);
    
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, ans[i]);
    }
    //cout << "total count : " << total_count << endl;
    
    clear(root);
    return 0;
}



Trie get_new_node() {
    Trie p = (Trie)calloc(sizeof(TrieNode), 1);
    p->childs = (TrieNode **)calloc(sizeof(TrieNode *), SIZE);
    return p;
}

void insert(Trie trie, char *buffer, int num) {
    Trie p = trie;
    for (int i = 0; buffer[i]; i++) {
        if (p->childs[buffer[i] - BASE] == NULL) {
            p->childs[buffer[i] - BASE] = get_new_node();
        }
        p = p->childs[buffer[i] - BASE];
    }
    p->count = 1;
    p->flag[++p->flag[0]] = num;
    return ;
}

void build_fail(Trie root) {
    // 将根节点的失败指针指向自身
    root->fail = root;
    queue<Trie> q;
    q.push(root);
    while (!q.empty()) {
        
        // 取出队首元素
        Trie now = q.front();
        q.pop();
        
        // 为该节点的26个子节点创建失败指针
        for (int i = 0; i < SIZE; i++) {
            if (now->childs[i] != NULL) {
                Trie child = now->childs[i];
                
                // 将根节点的子节点的失败指针指向根节点
                if (now == root) {
                    child->fail = root;
                } else {
                    
                    // 若当前节点不是根节点：
                    // 那么，当前节点的子节点的失败指针应该指向
                    // 当前指针的失败指针指向的的节点的对应的子节点，
                    // 若该节点为空，继续跳转失败指针，直到指向根节点或找到了一个合适的节点。
                    Trie iter = now;
                    while (iter != root && iter->fail->childs[i] == NULL) {
                        iter = iter->fail;
                    }
                    if (iter->fail->childs[i] != NULL) {
                        child->fail = iter->fail->childs[i];
                    } else {
                        child->fail = root;
                    }
                }
                q.push(child);
            }
        }
        
    }
    return ;
}

int match(Trie root, char *buffer, int *num) {
    Trie p = root;
    int total_count = 0;
    for (int i = 0; buffer[i]; i++) {
        while (p != root && p->childs[buffer[i] - BASE] == NULL) {
            p = p->fail;
        }
        p = p->childs[buffer[i] - BASE];
        if (p == NULL) {
            p = root;
        }
        Trie iter = p;
        while (iter != root) {
            if (iter->flag[0] > 0) {
                for (int i = 1; i <= iter->flag[0]; i++) {
                    num[iter->flag[i]] += iter->count;
                }
                // num[iter->flag - 1] += iter->count;
            }
            total_count += iter->count;
            iter = iter->fail;
        }
    }
    return total_count;

}

void clear(Trie root) {
    if (root == NULL) {
        return ;
    }
    Trie p = root;
    for (int i = 0; i < SIZE; i++) {
        clear(p->childs[i]);
    }
    free(p->childs);
    free(p);
    return ;
}

/* 计蒜客数据结构习题：字符串统计  */




