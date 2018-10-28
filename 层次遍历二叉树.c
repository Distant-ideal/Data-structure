/*************************************************************************
	> File Name: 层次遍历二叉树.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年10月25日 星期四 18时03分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = ch;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *build(char *str, Node *root, int init) {
    if (str[0] == 0) return NULL;
    static int i;
    if (init == 1) i = 0;
    Node *p = NULL; int flag = 0;
    while (str[i]) {
        switch (str[i]) {
            case '(' : {
                i += 1;
                p = build(str, p, 0);
            } break;
            case ')' : {
                if (root == NULL) return p;
                return root;
            } break;
            case ',' : {
                flag = 1;
            } break;
            case ' ' : {
            } break;
            default : {
                p = getNewNode(str[i]);
                if (root != NULL) {
                    if (flag == 0) root->lchild = p;
                    else root->rchild = p;
                }
            } break;
        }
        i += 1;
    }
    return (root ? root : p);
}

void del(Node *node, char x) {
    if (node == NULL) return ;
    if (node->lchild && node->lchild->key == x) {
    node->lchild = NULL;
        return ;
    }
    if (node->rchild && node->rchild->key == x) {
        node->rchild = NULL;
        return ;
    }
    del(node->lchild, x);
    del(node->rchild, x);
    return ;
} 

int output(Node *root, int x) {
    if (x < 0 || !root ) {
        return 0;
    }
    if (x == 0) {
        printf("%c ", root->key);
        return 1;
    }
    return output(root->lchild, x - 1) + output(root->rchild, x - 1); 
}

void out(Node *root) {
    for (int i = 0; i >= 0; i++) {
        if (!output(root, i)) break;
    }
    printf("\n");
}

int main() {
    char str[32], x;
    scanf("%[^\n]s", str);
    int len = strlen(str);
    if (str[0] != x) {
        Node *root = build(str, NULL, 1);
        out(root);
    }
    return 0;
}
