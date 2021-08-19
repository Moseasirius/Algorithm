//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_MOVEZEROES_H
#define USINGARRAY_MOVEZEROES_H
#include <iostream>
#include <vector>

using namespace std;

// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
// 时间复杂度: O(n)
// 空间复杂度: O(n)
namespace moveZeroes {
    class Solution {
    public:
        void moveZeroes(vector<int> &nums) {

            vector<int> nonZeroElements;

            // 将vec中所有非0元素放入nonZeroElements中
            for (int i = 0; i < nums.size(); i++)
                if (nums[i])
                    nonZeroElements.push_back(nums[i]);

            // 将nonZeroElements中的所有元素依次放入到nums开始的位置
            for (int i = 0; i < nonZeroElements.size(); i++)
                nums[i] = nonZeroElements[i];

            // 将nums剩余的位置放置为0
            for (int i = nonZeroElements.size(); i < nums.size(); i++)
                nums[i] = 0;
        }
    };
}

#endif //USINGARRAY_MOVEZEROES_H
