//
// Created by mozhenhai on 2021/8/20.
//

#ifndef DYNAMICPROGRAMMING_TEST_H
#define DYNAMICPROGRAMMING_TEST_H
#include "Climbing-Stairs.h"
#include "Integer-Break.h"
void climbStairsTest() {
    int n = 5;
    int res = climbStairs1::Solution().climbStairs(n);
    cout << res << endl;
}
void integerBreakTest(){
    int n=10;
    int res = integerBreak1::Solution().integerBreak(n);
    cout<<res;

}
void Knapsack01ITest(){

}

#endif //DYNAMICPROGRAMMING_TEST_H
