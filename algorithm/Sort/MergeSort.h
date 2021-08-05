//
// Created by mo on 2021/6/24.
//

#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

#include<iostream>

using namespace std;

//l:left m:middle r:right 使用的是左闭右闭区间[l,r]
template<typename T>
//__表示私有函数
void __merge(T array[], int l, int mid, int r) {
    T aux[r - l + 1];
    //
    for (int i = l; i <= r; i++) {
        aux[i - l] = array[i];
    }
    //初始化，i指向左半部分数组的起始索引位置l,j指向右半部分数组的起始索引位置mid+1
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid)//如果左半部分数组已经处理完毕
        {
            array[k] = aux[j - l];
            j++;
        } else if (j > r)//如果右半部分数组已经处理完毕
        {
            array[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l])//左半部分索引指的元素小于右半部分索引指的数组的元素
        {
            array[k] = aux[i - l];
            i++;
        } else//右半部分索引指的元素小于左半部分数组索引指的元素
        {
            array[k] = aux[j - l];
            j++;
        }

    }
}

template<typename T>
//__表示私有函数
void __mergesort(T array[], int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2; //等价于(l+r)/2 为了防止溢出，如果l和r都很大，两个很大int型的数相加可能会溢出
    __mergesort(array, l, mid);
    __mergesort(array, mid + 1, r);
    __merge(array, l, mid, r);
}

template<typename T>
void MergeSort(T array[], int length) {
    __mergesort(array, 0, length - 1);
}

#endif //SORT_MERGESORT_H
