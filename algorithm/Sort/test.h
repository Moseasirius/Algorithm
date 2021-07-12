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
#include "QuickSort.h"
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
void testQuickSort3ways()
{
    int n=15;
    int * array= SortTestHelper::generateRandomArray(n,0,n);
    cout<<"QuickSort3ways"<<endl;
    SortTestHelper::printArray(array,n);
    QuickSort3ways(array,n);
    SortTestHelper::printArray(array,n);
    delete [] array;
    return;
}
void testQuickSort()
{
    int n=100000;
    cout<<"Test for random array ,size= "<< n <<",random range [0," << n<<"]"<<endl;
    int *array1=SortTestHelper::generateRandomArray(n,0,n);
    int *array2=SortTestHelper::generateRandomArray(n,0,n);
    int *array3=SortTestHelper::generateRandomArray(n,0,n);
    cout<<"QuickSort"<<endl;
    SortTestHelper::testSort("Quick Sort",QuickSort,array1,n);
    cout<<"QuickSort2"<<endl;
    SortTestHelper::testSort("Quick Sort2",QuickSort2,array2,n);
    cout<<"QuickSort3"<<endl;
    SortTestHelper::testSort("Quick Sort3",QuickSort3ways,array3,n);

    delete [] array1;
    delete [] array2;
    delete [] array3;

    cout<<"Test for random array ,size= "<< n <<",random range [0," << 10<<"]"<<endl;
    int *array4=SortTestHelper::generateRandomArray(n,0,10);
    int *array5=SortTestHelper::generateRandomArray(n,0,10);
    int *array6=SortTestHelper::generateRandomArray(n,0,10);
    cout<<"QuickSort"<<endl;
    SortTestHelper::testSort("Quick Sort",QuickSort,array4,n);
    cout<<"QuickSort2"<<endl;
    SortTestHelper::testSort("Quick Sort2",QuickSort2,array5,n);
    cout<<"QuickSort3ways"<<endl;
    SortTestHelper::testSort("Quick Sort3",QuickSort3ways,array6,n);
    delete [] array4;
    delete [] array5;
    delete [] array6;

}


#endif //SORT_TEST_H
