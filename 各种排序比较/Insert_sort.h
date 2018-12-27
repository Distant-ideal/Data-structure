/*************************************************************************
	> File Name: Insert_sort.h
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月16日 星期日 18时02分28秒
 ************************************************************************/

#ifndef _INSERT_SORT_H
#define _INSERT_SORT_H

#define swap(a,b) {\
    __typeof(a) _temp = a; a = b; b = _temp;\
}

double insert_sort(int *num, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0 && num[j] < num[j - 1]; --j) {
            swap(num[j], num[j - 1]);
        }
    }
    return 1.0;
}

#endif
