/*************************************************************************
	> File Name: 稀疏多项式.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年10月12日 星期五 18时05分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEFAULT_AGR(a, b) ((#a)[0] ? a + 0 : b)
#define init(a) __init(DEFAULT_AGR(a , 10));

typedef struct data {
    int c, n;
} Data;

typedef struct Vector{
    int size, length;
    Data *data;
} Vector;


Vector *__init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (Data *)malloc(sizeof(Data) * n);
    p->size = n;
    p->length = 0;
    return p;
}

int expand (Vector *v) {
    Data *p = (Data *)realloc(v->data, sizeof(Data) * 2 * v->size);
    if(p == NULL) return 0;
    v->size *= 2;
    v->data = p;
    return 1;
}

int insert(Vector *v, Data value, int ind) {
    if(v->length == v->size) {
        expand(v);
        return 0;
    }
    if(ind < 0 || ind > v->length) return 0;
    for(int i = v->length - 1; i >= ind; i--) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = value;
    v->length += 1;
    return 1;
}

void clear(Vector *v) {
    if(v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

void output(Vector *v, int n) {
    int sum = 0;
    int s = 1;
    for(int i = 0; i < v->length; i++) {
        s = pow(n, v->data[i].n); 
        sum += v->data[i].c * s;
    }
    printf("%d\n", sum);
}

int main() {
    Vector *v1 = init(50);
    int m;
    scanf("%d", &m);
    Data data;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &data.c, &data.n);
        insert(v1, data, i);
    }
    int n;
    scanf("%d", &n);
    output(v1, n);
    clear(v1);
    return 0;
}
