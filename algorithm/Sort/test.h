//
// Created by mo on 2021/6/25.
//

#ifndef SORT_TEST_H
#define SORT_TEST_H
#include "SortTestHelper.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
void testBubbleSort()
{
    int n=15;
    int * array= SortTestHelper::generateRandomArray(n,0,n);
    cout<<"BubbleSort:"<<endl;
    SortTestHelper::printArray(array,n);
    BubbleSort(array,n);
    SortTestHelper::printArray(array,n);
    assert(SortTestHelper::isSorted(array,n));
    delete [] array;
    return;
}
void testSelectionSort()
{
    int n=15;
    int * array= SortTestHelper::generateRandomArray(n,0,n);
    cout<<"SelectionSort"<<endl;
    SortTestHelper::printArray(array,n);
    SelectionSort(array,n);
    SortTestHelper::printArray(array,n);
    delete [] array;
    return;
}
void testInsertionSort()
{
    int n=15;
    int * array= SortTestHelper::generateRandomArray(n,0,n);
    cout<<"InsertionSort"<<endl;
    SortTestHelper::printArray(array,n);
    InsertionSort(array,n);

    SortTestHelper::printArray(array,n);
    delete [] array;
    return;
}
void testMergeSort()
{
    int n=15;
    int * array= SortTestHelper::generateRandomArray(n,0,n);
    cout<<"MergeSort"<<endl;
    SortTestHelper::printArray(array,n);
    MergeSort(array,n);
    SortTestHelper::printArray(array,n);
    delete [] array;
    return;
}


#endif //SORT_TEST_H
