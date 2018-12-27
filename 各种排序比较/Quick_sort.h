/*************************************************************************
	> File Name: Quick_sort.h
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月16日 星期日 17时56分13秒
 ************************************************************************/

#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#define swap(a, b) {\
    __typeof(a) _temp = a; a = b; b = _temp;\
}
double quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while(num[x] < z) ++x;
            while(num[y] > z) --y;
            if(x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return 1.0;
}

#endif
