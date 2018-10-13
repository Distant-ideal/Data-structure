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
    printf("\n");
}
void clear (Vector *v) {
    if(v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

void move(Vector *v) {
    if(v->length == v->size) {
        if(v->length == v->size) {
            expand(v);
        }
    }
    v->data[v->length] = v->data[0];
    for(int j = 1; j <= v->length + 1; j++) {
        v->data[j - 1] = v->data[j];
    }
}

int main() {
    Vector *v = init();
    int m, n;
    scanf("%d %d", &m, &n);
    int x;
    for(int k = 0; k < m; k++) {
        scanf("%d", &x);
        insert(v, x, k);
    }
    for(int i = 1; i <= n; i++) {
        move(v);
    }
    output(v);
    clear(v);
    return 0;
}
