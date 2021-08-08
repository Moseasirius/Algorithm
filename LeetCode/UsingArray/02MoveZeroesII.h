//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_02MOVEZEROESII_H
#define USINGARRAY_02MOVEZEROESII_H
#include <iostream>
#include <vector>

using namespace std;

namespace moveZeroesII{
    // 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
// 时间复杂度: O(n)
// 空间复杂度: O(n)
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {

            vector<int> nonZeroElements;

            // 将vec中所有非0元素放入nonZeroElements中
            for(int i = 0 ; i < nums.size() ; i ++)
                if(nums[i])
                    nonZeroElements.push_back(nums[i]);

            // 将nonZeroElements中的所有元素依次放入到nums开始的位置
            for(int i = 0 ; i < nonZeroElements.size() ; i ++)
                nums[i] = nonZeroElements[i];

            // 将nums剩余的位置放置为0
            for(int i = nonZeroElements.size() ; i < nums.size() ; i ++)
                nums[i] = 0;
        }
    };
    void moveZeroesTest(){
        int arr[] = {0, 1, 0, 3, 12};
        vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

        Solution().moveZeroes(vec);

        for(int i = 0 ; i < vec.size() ; i ++)
            cout << vec[i] << " ";
        cout << endl;

    }

}
namespace moveZeroesII1{
    // 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
//
// 原地(in place)解决该问题
// 时间复杂度: O(n)
// 空间复杂度: O(1)
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {

            int k = 0; // nums中, [0...k)的元素均为非0元素

            // 遍历到第i个元素后,保证[0...i]中所有非0元素
            // 都按照顺序排列在[0...k)中
            for(int i = 0 ; i < nums.size() ; i ++)
                if(nums[i])
                    nums[k++] = nums[i];

            // 将nums剩余的位置放置为0
            for(int i = k ; i < nums.size() ; i ++)
                nums[i] = 0;
        }
    };
    void moveZeroesTest(){
        int arr[] = {0, 1, 0, 3, 12};
        vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

        Solution().moveZeroes(vec);

        for(int i = 0 ; i < vec.size() ; i ++)
            cout << vec[i] << " ";
        cout << endl;

    }


}
namespace moveZeroesII2{
    // 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
//
// 原地(in place)解决该问题
// 时间复杂度: O(n)
// 空间复杂度: O(1)
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {

            int k = 0; // nums中, [0...k)的元素均为非0元素

            // 遍历到第i个元素后,保证[0...i]中所有非0元素
            // 都按照顺序排列在[0...k)中
            // 同时, [k...i] 为 0
            for(int i = 0 ; i < nums.size() ; i ++)
                if(nums[i])
                    swap(nums[k++] , nums[i]);

        }
    };
    void moveZeroesTest(){
        int arr[] = {0, 1, 0, 3, 12};
        vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

        Solution().moveZeroes(vec);

        for(int i = 0 ; i < vec.size() ; i ++)
            cout << vec[i] << " ";
        cout << endl;

    }



}
namespace moveZeroesII3{
    // 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
//
// 原地(in place)解决该问题
// 时间复杂度: O(n)
// 空间复杂度: O(1)
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {

            int k = 0; // nums中, [0...k)的元素均为非0元素

            // 遍历到第i个元素后,保证[0...i]中所有非0元素
            // 都按照顺序排列在[0...k)中
            // 同时, [k...i] 为 0
            for(int i = 0 ; i < nums.size() ; i ++)
                if(nums[i])
                    if(k != i)
                        swap(nums[k++] , nums[i]);
                    else
                        k ++;
        }
    };
    void moveZeroesTest(){
        int arr[] = {0, 1, 0, 3, 12};
        vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

        Solution().moveZeroes(vec);

        for(int i = 0 ; i < vec.size() ; i ++)
            cout << vec[i] << " ";
        cout << endl;

    }
}

#endif //USINGARRAY_02MOVEZEROESII_H
