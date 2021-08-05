//
// Created by mo on 2021/6/24.
//

#ifndef SORT_SORTTESTHELPER_H
#define SORT_SORTTESTHELPER_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include <assert.h>

using namespace std;
namespace SortTestHelper {
    //生成有n个随机数的数组，每个元素的随机范围为[rangeL,rangeR]
    //这里只是使用int型数组，可以使用template<typename T>
    int *generateRandomArray(int n, int range_l, int range_r) {
        int *array = new int[n];
        //设置随机数种子
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            array[i] = rand() % (range_r - range_l + 1) + range_l;
        }
        return array;
        //注意这里申请了内存空间，使用完以后记得释放内存
    }

    //生成一个近乎有序的数组，
    //首先生成一个[0...n-1]的完全有序数组，然后随机交换swapTimes对数据
    //swapTimes定义了数组无序的程度
    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int pos1 = rand() % n;//交换的位置1
            int pos2 = rand() % n;//交换的位置2
            swap(array[pos1], array[pos2]);
        }
        return array;
        //这里申请了内存空间，使用完以后记得释放
    }

    //拷贝数组a中的元素的新的数组，并返回新的数组
    int *copyArray(int a[], int n) {
        int *array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = a[i];
        }
        return array;
        //这里申请了内存空间，使用完后记得释放
    }

    //打印数组内容
    template<typename T>
    void printArray(T array[], int n) {
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // 判断arr数组是否有序
    template<typename T>
    bool isSorted(T arr[], int n) {

        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;

        return true;
    }

//    //判断数组是否有序
//    template<typename T>
//    bool isOrderedArray(T array [],int n)
//    {
//        for(int i=0;i<n-1;i++)
//        {
//            if(array[i+1]<array[i])
//                return false;
//        }
//        return true;
//    }
    //测试排序算法Sort排序array数组所得结果的正确性和算法的运行时间
    template<typename T>
    void testSort(const string &sortName, void (*sort)(T [], int), T array[], int n) {
        clock_t startTime = clock();
        sort(array, n);
        clock_t endTime = clock();
//        cout<<endTime-startTime<<endl;
//        cout<<CLOCKS_PER_SEC<<endl;
        cout << sortName << " " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        //CLOCKS_PER_SEC 每秒钟的时钟周期数

        assert(isSorted(array, n));
//        cout<<isSorted(array,n)<<endl;
        cout << "######################" << endl;
        return;

    }

};
#endif //SORT_SORTTESTHELPER_H
