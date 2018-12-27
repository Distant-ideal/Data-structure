/*************************************************************************
	> File Name: Merge_sort.h
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月16日 星期日 18时10分53秒
 ************************************************************************/

#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

#define swap(a, b) {\
    __typeof(a) _temp = a; a = b; b = _temp;\
}


double merge_sort(int *num, int l, int r) {
    if(r - l <= 1) {
        if(r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return 1.0;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid || p2 <= r) {
        if(p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return 1.0;
}

#endif
