/*************************************************************************
	> File Name: Select_sort.h
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月16日 星期日 17时49分35秒
 ************************************************************************/

#ifndef _SELECT_SORT_H
#define _SELECT_SORT_H

#define swap(a,b) {\
    __typeof(a) _temp = a; a = b; b = _temp;\
}

double select_sort(int *num, int n) {
    for(int i = 0; i < n - 1; i++) {
        int ind = i;
        for(int j = i + 1; j < n; j++) {
            if(num[ind] > num[j]) ind = j;
        }
        swap(num[i], num[ind]);
    }
    return 1.0;
}

#endif
