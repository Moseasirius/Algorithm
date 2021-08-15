//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_SORTCOLORS_H
#define USINGARRAY_SORTCOLORS_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
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

    void SortColorsTest() {
        int array[] = {2, 0, 2, 1, 1, 0};
        vector<int> vec(array, array + sizeof(array) / sizeof(int));
        Solution().sortColors(vec);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;

    }

}
namespace sortColors2 {
    class Solution {
    public:
        void sortColors(vector<int> &nums) {
            int count[3] = {0};   // 存放0, 1, 2三个元素的频率
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

    void SortColorsTest() {
        int array[] = {2, 0, 2, 1, 1, 0};
        vector<int> vec(array, array + sizeof(array) / sizeof(int));
        Solution().sortColors(vec);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;

    }

}

#endif //USINGARRAY_SORTCOLORS_H
