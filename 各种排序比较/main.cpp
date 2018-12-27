/*************************************************************************
	> File Name: main.cpp
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月22日 星期六 12时42分16秒
 ************************************************************************/

#include <iostream>
#include <iomanip>
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

//执行消耗时间的宏
#define TEST_TIME(funs) ({\
    int begin = clock();\
    double ret = funs;\
    int end = clock();\
    cout << "Spend time : ";\
    cout << setiosflags(ios::fixed) << setprecision(5) << ((end - begin) * 1.0 / CLOCKS_PER_SEC * 1000) << "ms" << endl;\
    ret;\
})

//执行排序的宏
#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

//生成随机数
void randint(int *num, int n) {
    while(n--) num[n] = rand() % 100;
    return ;
}

//输出数组
void output(int *num, int n) {
    cout << "[" ;
    for(int i = 0; i < n; i++) {
        //printf(" %d", num[i]);
        cout << " " << num[i];
    }
    cout << " ]" << endl;
    return ;
}

//数组值的交换
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
    
    //选择排序
    copy(arr, original_arr, max_op);
    TEST(original_arr, max_op, select_sort, num, max_op);
    TEST_TIME(select_sort(arr, max_op));
    cout << endl;
    
    //快排
    TEST(original_arr, max_op, quick_sort, num, 0, max_op - 1);
    copy(original_arr, arr, max_op);
    TEST_TIME(quick_sort(arr, 0, max_op - 1));
    cout << endl;
    
    //插入排序
    TEST(original_arr, max_op, insert_sort, num, max_op);
    copy(original_arr, arr, max_op);
    TEST_TIME(insert_sort(arr, max_op));
    cout << endl;
    
    //起泡排序
    TEST(original_arr, max_op, bubble_sort, num, max_op);
    copy(original_arr, arr, max_op);
    TEST_TIME(bubble_sort(arr, max_op));
    cout << endl;
    
    //归并排序
    TEST(original_arr, max_op, merge_sort, num, 0, max_op - 1);
    copy(original_arr, arr, max_op);
    TEST_TIME(merge_sort(arr, 0, max_op - 1));
    cout << endl;
    
    //希尔排序
    TEST(original_arr, max_op, hill_sort, num, max_op);
    copy(original_arr, arr, max_op);
    TEST_TIME(hill_sort(arr, max_op));
    cout << endl;
    
    //堆排
    TEST(original_arr, max_op, heap_sort, num, max_op);
    copy(original_arr, arr, max_op);
    TEST_TIME(heap_sort(arr, max_op));
    
    return 0;
}
