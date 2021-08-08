//
// Created by mozhenhai on 2021/8/8.
//

#ifndef TIMECOMPLEXITY_RECURSIONTIMECOMPLEXITY_H
#define TIMECOMPLEXITY_RECURSIONTIMECOMPLEXITY_H
#include <iostream>
#include <cassert>

using namespace std;

// binarySearch
namespace RecursionTimeComplexity {
    int binarySearch(int arr[], int l, int r, int target) {

        if (l > r)
            return -1;

        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binarySearch(arr, l, mid - 1, target);
        else
            return binarySearch(arr, mid + 1, r, target);

    }

// sum
    int sum(int n) {

        assert(n >= 0);

        if (n == 0)
            return 0;
        return n + sum(n - 1);
    }

// pow2
    double pow(double x, int n) {

        assert(n >= 0);

        if (n == 0)
            return 1.0;

        double t = pow(x, n / 2);
        if (n % 2)
            return x * t * t;

        return t * t;
    }

// f
    int f(int n) {

        assert(n >= 0);

        if (n == 0)
            return 1;

        return f(n - 1) + f(n - 1);
    }

/*
// mergeSort
void mergeSort(int arr[], int l, int r){

    if(l >= r)
        return;

    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
*/
    void RecursionTimeComplexity() {
        cout << sum(100) << endl;
        cout << pow(2, 10) << endl;

    }

    void RecursionTimeComplexity1() {
        cout << f(10) << endl;

    }
}
#endif //TIMECOMPLEXITY_RECURSIONTIMECOMPLEXITY_H
