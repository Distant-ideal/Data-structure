/*************************************************************************
	> File Name: Hill_sort.h
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月16日 星期日 20时00分04秒
 ************************************************************************/

#ifndef _HILL_SORT_H
#define _HILL_SORT_H

double hill_sort(int *num, int n) {
    int j, i, k, temp;
    for(j = n / 2; j >= 1; j = j / 2){
        for(i = j; i < n; i++){
            temp = num[i];
            for(k = i - j; (k >= 0) && (num[k] > temp); k = k - j) {
                num[k + j] = num[k];
            }
            num[k + j] = temp;
        }
    }
    return 1.0;
}

#endif
