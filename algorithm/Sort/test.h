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
#include "HeapSort.h"
#include "IndexHeap.h"


void testBubbleSort() {
    int n = 15;
    int *array = SortTestHelper::generateRandomArray(n, 0, n);
    cout << "BubbleSort:" << endl;
    SortTestHelper::printArray(array, n);
    BubbleSort(array, n);
    SortTestHelper::printArray(array, n);
    assert(SortTestHelper::isSorted(array, n));
    delete[] array;
    return;
}

void testSelectionSort() {
    int n = 15;
    int *array = SortTestHelper::generateRandomArray(n, 0, n);
    cout << "SelectionSort" << endl;
    SortTestHelper::printArray(array, n);
    SelectionSort(array, n);
    SortTestHelper::printArray(array, n);
    delete[] array;
    return;
}

void testInsertionSort() {
    int n = 15;
    int *array = SortTestHelper::generateRandomArray(n, 0, n);
    cout << "InsertionSort" << endl;
    SortTestHelper::printArray(array, n);
    InsertionSort(array, n);

    SortTestHelper::printArray(array, n);
    delete[] array;
    return;
}

void testMergeSort() {
    int n = 15;
    int *array = SortTestHelper::generateRandomArray(n, 0, n);
    cout << "MergeSort" << endl;
    SortTestHelper::printArray(array, n);
    MergeSort(array, n);
    SortTestHelper::printArray(array, n);
    delete[] array;
    return;
}

void testQuickSort3ways() {
    int n = 15;
    int *array = SortTestHelper::generateRandomArray(n, 0, n);
    cout << "QuickSort3ways" << endl;
    SortTestHelper::printArray(array, n);
    QuickSort3ways(array, n);
    SortTestHelper::printArray(array, n);
    delete[] array;
    return;
}

void testQuickSort() {
    int n = 100000;
    cout << "Test for random array ,size= " << n << ",random range [0," << n << "]" << endl;
    int *array1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *array2 = SortTestHelper::generateRandomArray(n, 0, n);
    int *array3 = SortTestHelper::generateRandomArray(n, 0, n);
    cout << "QuickSort" << endl;
    SortTestHelper::testSort("Quick Sort", QuickSort, array1, n);
    cout << "QuickSort2" << endl;
    SortTestHelper::testSort("Quick Sort2", QuickSort2, array2, n);
    cout << "QuickSort3" << endl;
    SortTestHelper::testSort("Quick Sort3", QuickSort3ways, array3, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;

    cout << "Test for  nearly ordered array ,size= " << n << ",random range [0," << 10 << "]" << endl;
    int *array4 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *array5 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *array6 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    cout << "QuickSort" << endl;
    SortTestHelper::testSort("Quick Sort", QuickSort, array4, n);
    cout << "QuickSort2" << endl;
    SortTestHelper::testSort("Quick Sort2", QuickSort2, array5, n);
    cout << "QuickSort3ways" << endl;
    SortTestHelper::testSort("Quick Sort3", QuickSort3ways, array6, n);
    delete[] array4;
    delete[] array5;
    delete[] array6;

    // 测试3 测试存在包含大量相同元素的数组
    cout << "Test for random array ,size= " << n << ",random range [0," << n << "]" << endl;
    array1 = SortTestHelper::generateRandomArray(n, 0, 10);
    array2 = SortTestHelper::generateRandomArray(n, 0, 10);
    array3 = SortTestHelper::generateRandomArray(n, 0, 10);
    cout << "QuickSort" << endl;
    SortTestHelper::testSort("Quick Sort", QuickSort, array1, n);
    cout << "QuickSort2" << endl;
    SortTestHelper::testSort("Quick Sort2", QuickSort2, array2, n);
    cout << "QuickSort3" << endl;
    SortTestHelper::testSort("Quick Sort3", QuickSort3ways, array3, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;

}

void testHeapSort1() {
    MaxHeap<int> maxHeap = MaxHeap<int>(100);
    cout << maxHeap.size() << endl;
    int n = 15;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        maxHeap.insert(rand() % 100);//[0,100)
    }
    maxHeap.print();
    //maxHeap.testPrint();

//    while (!maxHeap.isEmpty())
    //将maxHeap中的数据通过extractMax取出来，
    //取出来的数据应该是从大到小顺序取出来的
    int *array = new int[n];
    for (int i = 0; i < n; i++) {
        array[i] = maxHeap.extractMax();
        cout << array[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i++) {
        assert(array[i - 1] >= array[i]);
    }
    delete[] array;
}

void testHeapSort2() {
    int n = 1000000;
    //测试1 一般性测试
    cout << "Test for random array ,size= " << n << ",random range [0," << n << "]" << endl;
    int *array1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *array2 = SortTestHelper::generateRandomArray(n, 0, n);
    int *array3 = SortTestHelper::generateRandomArray(n, 0, n);
    cout << "HeapSort1" << endl;
    SortTestHelper::testSort("HeapSort1", HeapSort1, array1, n);
    cout << "HeapSort2" << endl;
    SortTestHelper::testSort("HeapSort2", HeapSort2, array2, n);
    cout << "HeapSort3" << endl;
    SortTestHelper::testSort("HeapSort3", HeapSort3, array3, n);


    delete[] array1;
    delete[] array2;
    delete[] array3;

    // 测试2 测试近乎有序的数组
    cout << "Test for nearly ordered array ,size= " << n << ",random range [0," << 10 << "]" << endl;
    int *array4 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *array5 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *array6 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    cout << "HeapSort1" << endl;
    SortTestHelper::testSort("Heap Sort1", HeapSort1, array4, n);
    cout << "HeapSort2" << endl;
    SortTestHelper::testSort("Heap Sort2", HeapSort2, array5, n);
    cout << "HeapSort3" << endl;
    SortTestHelper::testSort("Heap Sort3", QuickSort3ways, array6, n);

    delete[] array4;
    delete[] array5;
    delete[] array6;

    // 测试3 测试存在包含大量相同元素的数组
    cout << "Test for random array ,size= " << n << ",random range [0," << n << "]" << endl;
    array1 = SortTestHelper::generateRandomArray(n, 0, 10);
    array2 = SortTestHelper::generateRandomArray(n, 0, 10);
    array3 = SortTestHelper::generateRandomArray(n, 0, 10);
    cout << "HeapSort1" << endl;
    SortTestHelper::testSort("HeapSort1", HeapSort1, array1, n);
    cout << "HeapSort2" << endl;
    SortTestHelper::testSort("HeapSort2", HeapSort2, array2, n);
    cout << "HeapSort3" << endl;
    SortTestHelper::testSort("HeapSort3", QuickSort3ways, array3, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;

}

void test() {
    int n = 10000;
    //测试1，一般测试
    cout << "Test for random array ,size= " << n << ",random range [0," << n << "]" << endl;

    int *array1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *array2 = SortTestHelper::copyArray(array1, n);
    int *array3 = SortTestHelper::copyArray(array1, n);
    int *array4 = SortTestHelper::copyArray(array1, n);
    int *array5 = SortTestHelper::copyArray(array1, n);

    SortTestHelper::testSort("Bubble Sort", BubbleSort, array1, n);
    SortTestHelper::testSort("Selection Sort", SelectionSort, array2, n);
    SortTestHelper::testSort("Insertion", InsertionSort, array3, n);
    SortTestHelper::testSort("Merge Sort", MergeSort, array4, n);
    SortTestHelper::testSort("Quick Sort", QuickSort, array5, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    delete[] array5;

    cout << endl;
}

void testIndexesHeap() {

}


#endif //SORT_TEST_H
