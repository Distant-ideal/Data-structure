/*************************************************************************
	> File Name: main.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月16日 星期日 17时20分08秒
 ************************************************************************/
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Select_sort.h"
#include "Quick_sort.h"
#include "Insert_sort.h"
#include "Bubble_sort.h"
#include "Merge_sort.h"
#include "Hill_sort.h"
#include "Heap_sort.h"

using namespace std;

#define TEST_TIME(funs) ({\
    int begin = clock();\
    double ret = funs;\
    int end = clock();\
    printf("%lfms\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000);\
    ret;\
})

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

void randint(int *num, int n) {
    while(n--) num[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("]\n");
    return ;
}

void copy(int *n, int *n2, int m) {
    for(int i = 0 ; i < m; i++) {
        n2[i] = n[i];
    }
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    int original_arr[max_op];
    randint(arr, max_op);
    copy(arr, original_arr, max_op);

    TEST(original_arr, max_op, select_sort, num, max_op);
    TEST_TIME(select_sort(arr, max_op));
    printf("\n");

    TEST(original_arr, max_op, quick_sort, num, 0, max_op - 1);
    copy(original_arr, arr, max_op);
    TEST_TIME(quick_sort(arr, 0, max_op - 1));
    printf("\n");
    
    TEST(original_arr, max_op, insert_sort, num, max_op);
    copy(original_arr, arr, max_op);
    TEST_TIME(insert_sort(arr, max_op));
    printf("\n");
    
    TEST(original_arr, max_op, bubble_sort, num, max_op);
    copy(original_arr, arr, max_op);
    TEST_TIME(bubble_sort(arr, max_op));
    printf("\n");

    TEST(original_arr, max_op, merge_sort, num, 0, max_op - 1);
    copy(original_arr, arr, max_op);
    TEST_TIME(merge_sort(arr, 0, max_op - 1));
    printf("\n");
    
    TEST(original_arr, max_op, hill_sort, num, max_op);
    copy(original_arr, arr, max_op);
    TEST_TIME(hill_sort(arr, max_op));
    printf("\n");
    
    output(original_arr, max_op);
    //heap_sort(arr, max_op);
    copy(original_arr, arr, max_op);
    TEST_TIME(heap_sort(arr, max_op));
    return 0;
}
