//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_SORTCOLORS_H
#define USINGARRAY_SORTCOLORS_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/
//
// 计数排序的思路
// 对整个数组遍历了两遍
// 时间复杂度: O(n)
// 空间复杂度: O(k), k为元素的取值范围

namespace sortColors1 {
    class Solution {
    public:
        void sortColors(vector<int> &nums) {
            int zero = -1;  // [0,zero] == 0
            int two = nums.size();  // [two,nums.size()-1] == 2
            // [zero+1,i) = 1;
            for (int i = 0; i < two;) {
                if (nums[i] == 1) {
                    i++;
                } else if (nums[i] == 2) {
                    swap(nums[--two], nums[i]);
                } else {//nums[i]==0
                    assert(nums[i] == 0);
                    swap(nums[++zero], nums[i++]);
                }
            }

        }
    };
}
// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/
//
// 三路快速排序的思想
// 对整个数组只遍历了一遍
// 时间复杂度: O(n)
// 空间复杂度: O(1)

namespace sortColors2 {
    class Solution {
    public:
        void sortColors(vector<int> &nums) {
            int count[3] = {0};   // 存放0, 1, 2三个元素的频率.
            for (int i = 0; i < nums.size(); i++) {
                assert(0 <= nums[i] && nums[i] <= 2);
                count[nums[i]]++;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (i < count[0]) nums[i] = 0;
                else if (i >= count[0] && i < count[0] + count[1]) nums[i] = 1;
                else {
                    assert(i >= count[0] + count[1]);
                    nums[i] = 2;
                }
            }
        }
    };
}

#endif //USINGARRAY_SORTCOLORS_H
