/*************************************************************************
	> File Name: 通话记录.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年10月21日 星期日 20时11分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    long long int *data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n; 
    q->cnt = 0;
    q->data = (long long int *)malloc(sizeof(long long int) * n );
    q->head = 0;
    q->tail = -1;
    return q;
}

int push (Queue *q, long long int value) {
    if(q->cnt == q->length) return 0;
    q->tail += 1;
    if(q->tail >= q->length) q->tail -= q->length;
    q->cnt += 1;
    q->data[q->tail] = value;
    return 1;
}

int empty(Queue *q) {
    return q->head > q->tail;
}

void pop(Queue *q) {
    if(empty(q)) return ;
    q->head += 1;
    if(q->head > q->length) q->head -= q->length;
    q->cnt -= 1;
    return ;
}
 
int front(Queue *q) {
    if(empty(q)) return 0;
    return q->data[q->head];
}

void output(Queue *q1, Queue *q2, Queue *q3) {
    for(int i = 0 ; i < 10; i++) {
        printf("%lld %lld %lld\n", q1->data[i], q2->data[i], q3->data[i]);
    }
    return ;
}

void clear(Queue *q) {
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    Queue *q1 = init(1000);
    Queue *q2 = init(1000);
    Queue *q3 = init(1000);
    long long int x, y;
    for(int i = 0; i < 10; i++){
    scanf("%lld %lld", &x, &y);
        if(x == 0) {
            push(q1, y);
        } else if(x == 1) {
            push(q2, y);
        } else if(x == 2) {
            push(q3, y);
        }
    }
    output(q1, q2, q3);
    clear(q1);
    clear(q2);
    clear(q3);
    return 0;
}
