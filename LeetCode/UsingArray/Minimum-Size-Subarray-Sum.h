//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_MINIMUM_SIZE_SUBARRAY_SUM_H
#define USINGARRAY_MINIMUM_SIZE_SUBARRAY_SUM_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
//
// 暴力解法
// 该方法在 Leetcode 中会超时！
// 时间复杂度: O(n^3)
// 空间复杂度: O(1)



// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
//
// 优化暴力解
// 时间复杂度: O(n^2)
// 空间复杂度: O(n)

// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
//
// 滑动窗口的思路
// 时间复杂度: O(n)
// 空间复杂度: O(1)

namespace MinimumSizeSubarraySum{
    class Solution{

    public:
        int minSubArrayLen(int target, vector<int>& nums) {

            int l = 0 , r = -1; //nums[l...r] 为我们的滑动窗口
            int sum = 0, res = nums.size()+1;
            while(l<nums.size()){
                if(r+1<nums.size()&&sum<target)
                    sum += nums[++r];
                else
                    sum -= nums[l++];
                if(sum>=target)

                    res = min(res,r-l+1);
            }
            if(res > nums.size()) return 0;
            return res;


        }
    };
}
// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
//
// 另外一个滑动窗口的实现, 仅供参考
// 时间复杂度: O(n)
// 空间复杂度: O(1)

// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
//
// 二分搜索
// 扩展main2的方法。对于每一个l, 可以使用二分搜索法搜索r
//
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)

#endif //USINGARRAY_MINIMUM_SIZE_SUBARRAY_SUM_H
