//
// Created by mozhenhai on 2021/8/13.
//

#ifndef USINGARRAY_TEST_H
#define USINGARRAY_TEST_H
#include <iostream>

#include "BinarySearch.h"
#include "MoveZeroes.h"
#include "MoveZeroesII.h"
#include "SortColors.h"
#include "Minimum-Size-Subarray-Sum.h"
#include "util.h"

void binarySearchTest1(){
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
void moveZeroesTest(){
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    moveZeroes::Solution().moveZeroes(vec);

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;

}
void moveZeroesII0Test(){
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    moveZeroesII0::Solution().moveZeroes(vec);

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;
}
void moveZeroesII1Test(){
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    moveZeroesII1::Solution().moveZeroes(vec);

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;
}
void moveZeroesII2Test(){
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    moveZeroesII2::Solution().moveZeroes(vec);

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;

}
void moveZeroesII3Test(){
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    moveZeroesII3::Solution().moveZeroes(vec);

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;

}
void SortColors1Test() {
    int array[] = {2, 0, 2, 1, 1, 0};
    vector<int> vec(array, array + sizeof(array) / sizeof(int));
    sortColors1::Solution().sortColors(vec);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
void SortColors2Test() {
    int array[] = {2, 0, 2, 1, 1, 0};
    vector<int> vec(array, array + sizeof(array) / sizeof(int));
    sortColors2::Solution().sortColors(vec);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

}

void minSubArrayLenTest(){
    int array[] = {5,1,3,5,10,7,4,9,2,8};
    vector<int> vec(array, array + sizeof(array) / sizeof(int));

    int res;
    res = MinimumSizeSubarraySum::Solution().minSubArrayLen(15,vec);
    cout<<res<<endl;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}


#endif //USINGARRAY_TEST_H
