//
// Created by mozhenhai on 2021/8/15.
//

#ifndef DYNAMICPROGRAMMING_CLIMBING_STAIRS_H
#define DYNAMICPROGRAMMING_CLIMBING_STAIRS_H

#include <iostream>
#include <vector>

using namespace std;


/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
/// 记忆化搜索
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
/// 动态规划
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)

namespace climbStairs1 {
    class Solution {
    public:
        int climbStairs(int n) {

            int one = 1;
            int two = 2;
            int resSum = 0;
            if (n == 1) return one;
            if (n == 2) return two;
            for (int i = 3; i <= n; i++) {
//                cout << i << endl;
                resSum = one + two;
//                cout<<resSum<<endl;
                one = two;
                two = resSum;
            }
                return resSum;
        }
    };
}



#endif //DYNAMICPROGRAMMING_CLIMBING_STAIRS_H
