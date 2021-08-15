//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_BINARYSEARCH_H
#define USINGARRAY_BINARYSEARCH_H
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"
using namespace std;

template<typename T>
int binarySearch1(T arr[], int n, T target){

    int l = 0, r = n - 1; // 在[l...r]的范围里寻找target
    while(l <= r){    // 当 l == r时,区间[l...r]依然是有效的
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) return mid;
        if(target > arr[mid])
            l = mid + 1;  // target在[mid+1...r]中; [l...mid]一定没有target
        else    // target < arr[mid]
            r = mid - 1;  // target在[l...mid-1]中; [mid...r]一定没有target
    }

    return -1;
}
template<typename T>
int binarySearch2(T arr[], int n, T target){

    int l = 0, r = n; // target在[l...r)的范围里
    while(l < r){    // 当 l == r 时, 区间[l...r)是一个无效区间
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) return mid;
        if(target > arr[mid])
            l = mid + 1;    // target在[mid+1...r)中; [l...mid]一定没有target
        else// target < arr[mid]
            r = mid;        // target在[l...mid)中; [mid...r)一定没有target
    }

    return -1;
}
void binarySearchTest(){
    int n = pow(10, 7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for(int i = 0 ; i < n ; i ++)
        assert(i == binarySearch1(data, n, i));
    clock_t endTime = clock();

    cout << "Binary Search test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

}
void binarySearchTest2(){
    int n = pow(10, 7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for( int i = 0 ; i < n ; i ++ )
        assert( i == binarySearch2(data, n, i) );
    clock_t endTime = clock();

    cout << "Binary Search2 test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

}
#endif //USINGARRAY_BINARYSEARCH_H
