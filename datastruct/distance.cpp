/*
 *	 File Name:    distance.cpp
 *	 Author:       sunowsir
 *	 Mail:         sunowsir@protonmail.com
 *	 Created Time: 2018年10月23日 星期二 19时38分57秒
 */

#include <cstdio>
#include <cstdlib>

#define MAX_N 1000
#define MAX_K 20

struct Edge {
    /* v : value; v : brother */
    int v, n;
} g[MAX_N << 1];

/* The 'cnt' variable stores the number of current node. */
/* The 'head[]' array stores the number of all node one of son node. */
int head[MAX_N + 5] = {0}, cnt = 0;

/* Add edge. */
inline void add(int a, int b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
    return ;
}

/* Multiplier. */
/* The 'gas[i][j]' array is the node number of the node i jump up tow to the jth power step.*/
int gas[MAX_N][MAX_K], dep[MAX_N] = {0};

void dfs(int u, int father) {
    /* Go up two to the 0th power step, that is one step is the parent of node u.  */
    gas[u][0] = father;
    /* The depth of node u is the depth of its parent node plus one. */
    dep[u] = dep[father] + 1;
    for (int i = 1; i < MAX_K; i++) {
        /* Jump up two to the ith power step = jump up two to (i - 1)th power step and go up two to the (i - 1)th of the second step.
        * 2 ^ i = 2 ^ (i - 1) + 2 ^ (i - 1);
        * */
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    
    /* Traversing all son nodes of node 'u' and recursively */
    for (int i = head[u]; i; i = g[i].n) {
        if (g[i].v == father) {
            continue;
        }
        dfs(g[i].v, u);
    }
    return ;
}

/* Returns the nearset common ancestor of node a and node b. */
int lca(int a, int b) {
    /* swap a and b */
    if (dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int l = dep[b] - dep[a];
    /*对齐 倍增*/
    for (int i = 0; i < MAX_K; i++) {
        if (l & 1 << i) {
            b = gas[b][i];
        }
    }
    if (a == b) {
        return a;
    }

    /* By superposing(叠加) one to two powers of two ,you can get any interget from n to the poer of n. */
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (gas[a][i] != gas[b][i]) {
            a = gas[a][i];
            b = gas[b][i];
        }
    }
    return gas[a][0];
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    while (~scanf("%d%d", &a, &b)) {
        printf("lca(%d, %d) = %d, %d -> %d = %d\n", a, b, lca(a, b), a, b, dep[a] + dep[b] - 2 * dep[a]);
    }

    return 0;
}

