/*************************************************************************
	> File Name: 寻找最近公共祖先.cpp
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年10月23日 星期二 19时38分54秒
 ************************************************************************/
//为什么0结点不使用
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#define MAX_N 1000
#define MAX_K 20

struct Edge {
    int v, n;
    //v边,n点
} g[MAX_N << 1];

int head[MAX_N + 5] = {0}, cnt = 0;

inline void add(int a, int b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
    return ;
}

//gas[i][j] -> i点往上走2^j步所能到达的祖先结点编号
int gas[MAX_N][MAX_K], dep[MAX_N] = {0};

void dfs(int u, int father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for(int i = 1; i < MAX_K; i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
        //求u向上的2个结点gas[u][i-1]已知相当于向上跳了2
    }
    for(int i = head[u]; i; i = g[i].n) {
        if(g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return ;
}

int lca(int a, int b) {
    if(dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int l = dep[b] - dep[a];
    for(int i = 0; i < MAX_K; i++) {
        if((l & (1 << i))) b = gas[b][i];
        //对齐的操作
        //l的相关二进制位是否为1
        //如果为1向上跳2^i步
        //二进制以5为例2^0和2^2时成立进行跳跃
        //跳跃1步跳跃4步
        //倍增法
    }
    if(a == b) return a;
    for(int i = MAX_K - 1; i >= 0; i--) {
        if(gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
        //一起走的操作
        //会跳到公共祖先之下的下一个结点
        //先上跳10步为例二进制a与b向上跳8步再跳2步
        //二进制的组合一起可以跳任意的深度
    }
    return gas[a][0];
}

int main() {
    int n;
    int a, b;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }
    //选取任意结点作为根节点无法影响最短距离
    dfs(1, 0);
    while (scanf ("%d%d", &a, &b) != EOF) {
        printf("lca(%d, %d) = %d, a -> b = %d\n", a, b, lca(a, b), dep[a] + dep[b] - 2 * dep[lca(a, b)]);
    }
    return 0;
}
