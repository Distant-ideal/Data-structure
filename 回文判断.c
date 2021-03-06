#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
  int *data;
    int top, size;
} stack;

stack *init(int n) {
  stack *s = (stack *)malloc(sizeof(stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int push (stack *s, int value) {
    if (s->top + 1 >= s->size) return 0;
    s->top++;
    s->data[s->top] = value;
    return 1;
}

int empty(stack *s) {
    return s->top == -1;
}

int top(stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

void pop(stack *s) {
    if (empty(s)) return ;
    s->top--;
}
int main() {
    stack *s = init(40);
    char str[40];
    int x = 0;
    scanf("%s", str);
    for (int i = 0; i < strlen(str) - 1; i++) {
        if (i > 20) break;
        push(s, str[i]);
    }
    char cmp[40];
    for (int i = 0; i < strlen(str) - 1; i++) {
        if (i > 20) break;
        if (str[i] != top(s)) {
            x = 1; 
            break;
        }
        pop(s);
    }
    if (x == 1) {
        printf("false\n");
    } else 
        printf("true\n");
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
  int *data;
    int top, size;
} stack;

stack *init(int n) {
  stack *s = (stack *)malloc(sizeof(stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int push (stack *s, int value) {
    if (s->top + 1 >= s->size) return 0;
    s->top++;
    s->data[s->top] = value;
    return 1;
}

int empty(stack *s) {
    return s->top == -1;
}

int top(stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

void pop(stack *s) {
    if (empty(s)) return ;
    s->top--;
}
int main() {
    stack *s = init(40);
    char str[40];
    int x = 0;
    scanf("%s", str);
    for (int i = 0; i < strlen(str) - 1; i++) {
        if (i > 20) break;
        push(s, str[i]);
    }
    char cmp[40];
    for (int i = 0; i < strlen(str) - 1; i++) {
        if (i > 20) break;
        if (str[i] != top(s)) {
            x = 1; 
            break;
        }
        pop(s);
    }
    if (x == 1) {
        printf("false\n");
    } else 
        printf("true\n");
    return 0;
}
