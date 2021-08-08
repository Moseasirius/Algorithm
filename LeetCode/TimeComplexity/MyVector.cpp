//
// Created by mozhenhai on 2021/8/8.
//
#include "MyVector.h"
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

__attribute__((unused)) void amortizedTime(){
    for(int i = 10 ; i <= 26 ; i ++){

        int n = pow(2, i);

        clock_t startTime = clock();
        MyVector<int> vec;
        for(int num = 0 ; num < n ; num ++){
            vec.push_back(num);
        }
        clock_t endTime = clock();

        cout << n << " operations: \t";
        cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
}

__attribute__((unused)) void amortizedTime1(){
    for(int i = 10 ; i <= 26 ; i ++){

        int n = pow(2, i);

        clock_t startTime = clock();
        MyVector<int> vec;
        for(int num = 0 ; num < n ; num ++)
            vec.push_back(i);
        for(int num = 0 ; num < n ; num ++)
            vec.pop_back();
        clock_t endTime = clock();

        cout << 2 * n << " operations: \t";
        cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

  }
}
