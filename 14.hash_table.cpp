/*************************************************************************
	> File Name: 14.hash_table.cpp
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年11月06日 星期二 20时41分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size; //大小
} HashTable;

Node *init_node(char *str, Node *head) { //原链表头结点
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);//拷贝
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *) malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

//APHash ZobristHash

int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for(int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    //int times = 0;
    h->data[ind] = init_node(str, h->data[ind]);
    //Node *node = init_node(str, h->data[ind]);
    //while(h->data[ind] != NULL) {
    //    times++;
    //    ind += times * times;
    //    ind %= h->size;
    //} //第一次加1的平方以此类推越跳越远
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while(p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

void clear_node(Node *node) {
    if(node == NULL) return ;
    Node *p = node, *q;
    while(p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for(int i = 0; i < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    char str[100];
    HashTable *h = init_hashtable(100);
    while(scanf("%d%s", &op, str) != EOF) {
        switch(op) {
            case 0 : {
                printf("insert %s to hash table\n", str);
                insert(h, str);
            }
            case 1 : {
                printf("search %s from hash table\n", search(h, str));           
                       }
            case 2 : 
        }
    }
    return 0;
}
