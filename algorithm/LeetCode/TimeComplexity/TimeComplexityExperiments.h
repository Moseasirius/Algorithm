//
// Created by mozhenhai on 2021/8/8.
//

#ifndef TIMECOMPLEXITY_TIMECOMPLEXITYEXPERIMENTS_H
#define TIMECOMPLEXITY_TIMECOMPLEXITYEXPERIMENTS_H
#include <iostream>
#include <cmath>
#include <ctime>
#include "MyUtil.h"
#include "MyAlgorithmTester.h"

void timeComplexityExperiments1(){

    // 数据规模倍乘测试findMax
    // O(n)
    cout << "Test for findMax:" << endl;
    for( int i = 10 ; i <= 28 ; i ++ ){

        int n = pow(2, i);
        int *arr = MyUtil::generateRandomArray(n, 0, 100000000);

        clock_t startTime = clock();
        MyAlgorithmTester::findMax(arr, n);
        clock_t endTime = clock();

        cout << "data size 2^" << i << " = " << n << "\t";
        cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

        delete[] arr;
    }
}
    void timeComplexityExperiments2(){
        // 数据规模倍乘测试selectionSort
        // O(n^2)
        cout << "Test for Selection Sort:" << endl;
        for( int i = 10 ; i <= 16 ; i ++ ){

            int n = pow(2, i);
            int *arr = MyUtil::generateRandomArray(n, 0, 100000000);

            clock_t startTime = clock();
            MyAlgorithmTester::selectionSort(arr, n);
            clock_t endTime = clock();

            cout << "data size 2^" << i << " = " << n << "\t";
            cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

            delete[] arr;
        }


    }
    void timeComplexityExperiments3(){
        // 数据规模倍乘测试binarySearch
        // O(logn)
        cout << "Test for Binary Search:" << endl;
        for(int i = 10 ; i <= 28 ; i ++){

            int n = pow(2, i);
            int *arr = MyUtil::generateOrderedArray(n);

            clock_t startTime = clock();
            MyAlgorithmTester::binarySearch(arr, n, 0);
            clock_t endTime = clock();

            cout << "data size 2^" << i << " = " << n << "\t";
            cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

            delete[] arr;
        }


    }
    void timeComplexityExperiments4(){
        // 数据规模倍乘测试mergeSort
        // O(nlogn)
        cout << "Test for Merge Sort:" << endl;
        for( int i = 10 ; i <= 26 ; i ++ ){

            int n = pow(2,i);
            int *arr = MyUtil::generateRandomArray(n, 0, 1<<30);

            clock_t startTime = clock();
            MyAlgorithmTester::mergeSort(arr, n);
            clock_t endTime = clock();

            cout << "data size 2^" << i << " = " << n << "\t";
            cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

            delete[] arr;
        }

    }

#endif //TIMECOMPLEXITY_TIMECOMPLEXITYEXPERIMENTS_H
