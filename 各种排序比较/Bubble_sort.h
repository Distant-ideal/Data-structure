/*************************************************************************
	> File Name: Bubble_sort.h
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月16日 星期日 18时01分15秒
 ************************************************************************/

#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

#define swap(a,b) {\
    __typeof(a) _temp = a; a = b; b = _temp;\
}

double bubble_sort(int *num, int n) {
    int times = 1;
    for(int i = 1; i < n && times; i++) {
        times = 0;
        for(int j = 0; j < n - i; j++) {
            if(num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
    }
    return 1.0;
}

#endif
