/*************************************************************************
	> File Name: 有序集合的交运算.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年10月12日 星期五 20时35分30秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_ARG(a, b) ((#a)[0] ? a + 0 : b)
#define init(a) __init(DEFAULT_ARG(a, 10))

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *__init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *)malloc(sizeof(int) *n);
    p->size = n;
    p->length = 0;
    return p;
}

int expand(Vector *v) {
    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size);
    if(p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    return 1;
}

int insert(Vector *v, int value, int ind) {
    if(v->length == v->size) {
        if(expand(v) == 0) {
            return 0;
        }
    }
    if(ind < 0 || ind > v->length) return 0;
    for(int i = v->length - 1; i >= ind; --i) {
        v->data[i + 1] = v->data[i];
    } 
    v->data[ind] = value;
    v->length += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    if(v->length == 0) return 0;
    if(ind < 0 || ind >= v->length) return 0;
    for(int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void output (Vector *v) {
    printf("%d", v->data[0]);
    for(int i = 1; i < v->length; i++) {
        printf("% d", v->data[i]);
    }
}

void clear (Vector *v) {
    if(v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

void find(int n, int m, Vector *v1, Vector *v2, Vector *v3) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v1->data[i] == v2->data[j]) {
                insert(v3, v1->data[i], s);
                s++;
            }
        }
    }
    if(s != 0) {
        printf("%d\n", v3->length);
        output(v3);
    } else {
        printf("%d\n", s);
    }
    return ;
}

int main() {
    Vector *v1 = init();
    Vector *v2 = init();
    Vector *v3 = init();
    int x, y, n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(v1, x, i);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &y);
        insert(v2, y, i);
    }
    find(n, m, v1, v2, v3);
    
    clear(v1);
    clear(v2);
    clear(v3);
    return 0;
}
