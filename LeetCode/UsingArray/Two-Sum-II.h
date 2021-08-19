//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_TWO_SUM_II_H
#define USINGARRAY_TWO_SUM_II_H
#include <vector>
// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//
// 暴力枚举法
// 时间复杂度: O(n^2)
// 空间复杂度: O(1)

//
namespace twoSumII1{
    class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {

            for(int i=0;i<numbers.size();i++){
                for(int j=i+1;j<numbers.size();j++){


                }

            }





        }
    };
}
// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//
// 二分搜索法
// 时间复杂度: O(nlogn)
// 空间复杂度: O(1)
namespace twoSumII2{
    class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {



        }
    };
}
// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//
// 对撞指针
// 时间复杂度: O(n)
// 空间复杂度: O(1)
namespace twoSumII3{
    class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {

            assert(numbers.size()>=2);

            int l = 0,r =numbers.size()-1;
            while(l<r){

                if(numbers[l]+numbers[r]==target){
                    int arr [2] = {l+1,r+1};
                    vector<int> vec(arr,arr+2);
                    return vec;
                }
                else if(numbers[l]+numbers[r]>target)
                    r--;
                else//numbers[l]+numbers[r]<target
                    l++;
            }
            throw invalid_argument("The input has no solution");

        }
    };
}
#endif //USINGARRAY_TWO_SUM_II_H
