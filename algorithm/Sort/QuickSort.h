//
// Created by mo on 2021/6/24.
//

#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

#endif //SORT_QUICKSORT_H

//对array[l,r]部分进行partition操作
//返回p 使得arr[l,p-1]<arr[p];arr[p+1,r]>arr[p]
template<typename T>
int __partition(T array[], int l, int r) {
    swap(array[l], array[rand() % (r - l + 1) + l]);//[l,r]的任意一个索引
    T v = array[l];

    //array[l+1,j]<v array[j+1,i)>v 为什么是开区间 因为当前考察的是第i个元素
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (array[i] < v) {
            swap(array[j + 1], array[i]);
            j++;
        }
    }
    swap(array[l], array[j]);
    return j;
}

//对array[l,r]部分进行快速排序
template<typename T>
void __quickSort(T array[], int l, int r) {
    if (l >= r)
        return;
    int p = __partition(array, l, r);
    __quickSort(array, l, p - 1);
    __quickSort(array, p + 1, r);
}

template<typename T>
void QuickSort(T array[], int n) {
    srand(time(NULL));
    __quickSort(array, 0, n - 1);
}
//
//如果标定点每次都选数组的首位,在对一个近似有序的数组进行快排的时候，其时间复杂度会退化为O(n^2)级别。
//解决办法 随机选取一个元素。


//双路快速排序，解决重复值较多的数组的情况,把=v的元素分散到两侧，防止有大量重复元素时退化成O(n^2)
//重复键值的序列，快排退化为O(n2)。之前写的代码。在有大量重复value的情况下，partition的部分，会变得极端的不平衡。
//QuickSort2
//对array[l,r]进行partition操作
template<typename T>
int __partition2(T array[], int l, int r) {
    swap(array[l], array[rand() % (r - l + 1) + l]);//[l,r]的任意一个索引
    T v = array[l];

    //array[l+1,j]<=v array(j+1,i]>=v
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && array[i] < v) i++;
        while (j >= l + 1 && array[j] > v) j--;
        if (i > j) break;
        swap(array[i], array[j]);
        i++;
        j--;
    }
    swap(array[l], array[j]);
    return j;
}

//对array[l,r]部分进行快速排序
template<typename T>
void __quickSort2(T array[], int l, int r) {
    if (l >= r)
        return;

    int p = __partition2(array, l, r);
    __quickSort2(array, l, p - 1);
    __quickSort2(array, p + 1, r);
}

template<typename T>
void QuickSort2(T array[], int n) {
    srand(time(NULL));
    __quickSort2(array, 0, n - 1);
}

//递归三路快速排序算法
template<typename T>
void __quickSort3ways(T array[], int l, int r) {
    if (l >= r)
        return;

    swap(array[l], array[rand() % (r - l + 1) + l]);//[l,r]的任意一个索引
    T v = array[l];

    int lt = l; //array[l+1,lt]<v
    int gt = r + 1; //array[gt,r]>v
    int i = l + 1;//array[lt+1,i]==v

    while (i < gt) {
        if (array[i] < v) {
            swap(array[i], array[lt + 1]);
            i++;
            lt++;
        } else if (array[i] > v) {
            swap(array[i], array[gt - 1]);
            gt--;
        } else//array[i]==v
        {
            i++;
        }
    }
    swap(array[l], array[lt]);
    __quickSort3ways(array, l, lt - 1);
    __quickSort3ways(array, gt, r);
}

template<typename T>
void QuickSort3ways(T array[], int n) {
    srand(time(NULL));
    __quickSort3ways(array, 0, n - 1);
}