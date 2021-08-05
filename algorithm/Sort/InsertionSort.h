//
// Created by mo on 2021/6/24.
//

#ifndef SORT_INSERTIONSORT_H
#define SORT_INSERTIONSORT_H

#include <algorithm>

template<typename T>
void InsertionSort(T array[], int length) {
    //假设i前面已经排好序
    for (int i = 1; i < length; i++) {
        //从i往前比较，如果大于或者等于就停止比较，如果小于就交换
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)//注意这种写法j不能等于0 因为j-1会数组越界，产生错误。
        {
            swap(array[j - 1], array[j]);
        }
        //或者可以写成这样
//        for(int j=i;j>=0;j--)
//        {
//            if(array[j-1]>array[j])
//                swap(array[j-1],array[j]);
//            else
//                break;//之前自己忘记写如果条件不满足break循环，导致一些错误，就是数组元素变为很大的值，可能是数组越界了
//        }
    }
}

//第一种插入排序交换次数比较多，优化，只需要比较，需要最后一次交换。
template<typename T>
void InsertionSort_advance(T array[], int length) {
    //假设i前面已经排好序
    for (int i = 1; i < length; i++) {
        //从i往前比较，如果小于就一直比较，直到大于等于就停止比较
        int key = array[i];
        int j;
        for (j = i; j >= 0 && array[j - 1] > key; j--)
            array[j] = array[j - 1];
        array[j] = key;//这里的array[j]与上一行的array[j]不一样
    }
}

#endif //SORT_INSERTIONSORT_H
