//
// Created by mozhenhai on 2021/8/15.
//

#ifndef DYNAMICPROGRAMMING_INTEGER_BREAK_H
#define DYNAMICPROGRAMMING_INTEGER_BREAK_H
#include <iostream>
#include <algorithm>
#include <vector>

/// 343. Integer Break
/// https://leetcode.com/problems/integer-break/description/
/// 暴力搜索
/// 在Leetcode中提交这个版本的代码会超时! (Time Limit Exceeded)
/// 时间复杂度: O(n^n)
/// 空间复杂度: O(n)

/// 343. Integer Break
/// https://leetcode.com/problems/integer-break/description/
/// 记忆化搜索
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)

/// 343. Integer Break
/// https://leetcode.com/problems/integer-break/description/
/// 动态规划
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
namespace integerBreak1{
    class Solution {
    private:
        vector<int> memo;

        //将n进行分割 至少分割两部分 可以获得的最大乘积
        int breakInteger(int n){
            if(n==1)
                return 1;
            if(memo[n]!=-1)
                return memo[n];
            int res=-1;
            for(int i=1;i<n;i++){
                res = max(res,max(i*(n-i),i* breakInteger(n-i)));
            }
            memo[n] = res;
            return res;
        }
    public:
        int integerBreak(int n) {
            memo = vector<int>(n+1,-1);
            int re = breakInteger(n);
            return re;
        }
    };

}

#endif //DYNAMICPROGRAMMING_INTEGER_BREAK_H
