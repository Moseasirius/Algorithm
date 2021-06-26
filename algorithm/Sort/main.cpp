#include <iostream>
#include "test.h"
#include <assert.h>
int main() {
//    std::cout << "Hello, World!" << std::endl;
//    testBubbleSort();
//    testSelectionSort();
//    testInsertionSort();
//    testMergeSort();

    int n=20000;
    //测试1，一般测试
    cout<<"Test for random array ,size= "<< n <<",random range [0," << n<<"]"<<endl;

    int *array1 = SortTestHelper::generateRandomArray(n,0,n);
    int *array2 = SortTestHelper::copyArray(array1,n);
    int *array3 = SortTestHelper::copyArray(array1,n);
    int *array4 = SortTestHelper::copyArray(array1,n);

    SortTestHelper::testSort("Bubble Sort",BubbleSort,array1,n);
    SortTestHelper::testSort("Selection Sort",SelectionSort,array2,n);
    SortTestHelper::testSort("Insertion",InsertionSort,array3,n);
    SortTestHelper::testSort("Merge Sort",MergeSort,array4,n);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;

    cout<<endl;
    return 0;
}
