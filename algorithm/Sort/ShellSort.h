//
// Created by mo on 2021/6/24.
//

#ifndef SORT_SHELLSORT_H
#define SORT_SHELLSORT_H

template<typename T>
void ShellSort(T array[], int length) {
    //计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int step = 1;
    while (step < length / 3)
        step = step * 3 + 1;//跳出循环之后，step为increment sequence 的一项，该项大于或等于且最靠近length/3

    while (step >= 1) {
        //思想就是，按步长分组，每一组按照插入排序思想排序
        for (int i = step; i < length; i++) {
            //插入排序思想
            for (int j = i; j >= 0 && array[j - setp] > array[j]; j--) {
                swap(array[j - step], array[j]);
            }
        }
        step = step / 3;//步长变小
    }
}

void ShellSort_advance(T array[], int length) {
    //计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int step = 1;
    while (step < length / 3)
        step = step * 3 + 1;//跳出循环之后，step为increment sequence 的一项，该项大于或等于且最靠近length/3
    //int step = length/2;//可以这样设置步长
    while (step >= 1) {
        //思想就是，按步长分组，每一组按照插入排序思想排序
        for (int i = step; i < length; i++) {
            //插入排序思想
            int j;
            int key = array[i];
            for (j = i; j >= 0 && array[j - setp] > key; j--) {
                array[j] = array[j - step];
            }
            array[j] = key;
        }
        step = step / 3;//步长变小
        //step=step/2;
    }
}

#endif //SORT_SHELLSORT_H
