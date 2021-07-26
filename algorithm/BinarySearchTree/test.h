//
// Created by mo on 2021/7/26.
//

#ifndef BINARYSEARCHTREE_TEST_H
#define BINARYSEARCHTREE_TEST_H
#include <iostream>
#include <cassert>
#include <ctime>

#include "BinarySearch.h"
#include "SequenceST.h"

using namespace std;
void testBinarySearch(){
        int n = 1000000;
        int* a = new int[n];
        for( int i = 0 ; i < n ; i ++ )
        a[i] = i;

        // 测试非递归二分查找法
        clock_t startTime = clock();

        // 对于我们的待查找数组[0...N)
        // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
        // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
        for( int i = 0 ; i < 2*n ; i ++ ){
            int v = binarySearch2(a, n, i);
            if( i < n )
                assert( v == i );
            else
                assert( v == -1 );
        }
        clock_t endTime = clock();
        cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;


        // 测试递归的二分查找法
        startTime = clock();

        // 对于我们的待查找数组[0...N)
        // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
        // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
        for( int i = 0 ; i < 2*n ; i ++ ){
            int v = binarySearch2(a, n, i);
            if( i < n )
                assert( v == i );
            else
                assert( v == -1 );
        }
        endTime = clock();
        cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

        delete[] a;
}
// 测试二分搜索树和顺序查找表之间的性能差距
// 二分搜索树的性能远远优于顺序查找表
void testBSTvsSequenceST(){


}

#endif //BINARYSEARCHTREE_TEST_H
