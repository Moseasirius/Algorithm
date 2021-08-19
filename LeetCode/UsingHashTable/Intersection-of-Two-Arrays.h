//
// Created by mozhenhai on 2021/8/16.
//

#ifndef USINGHASHTABLE_INTERSECTION_OF_TWO_ARRAYS_H
#define USINGHASHTABLE_INTERSECTION_OF_TWO_ARRAYS_H
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;
// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)

//map 和 set 的底层实现为平衡二叉树
//unordered_map 和unordered_set 的底层实现为哈希表

namespace IntersectionOfTwoArrays{

    class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

            unordered_set<int> record;
            for(int i=0;i<nums1.size();i++)
                record.insert(nums1[i]);

            unordered_set<int> result;

            for(int i=0;i<nums2.size();i++){
                if(record.find(nums2[i])!=record.end())
                    result.insert(nums2[i]);
            }


            vector<int> resultVector;
            for(unordered_set<int>::iterator iter=result.begin();iter!=result.end();iter++)
                resultVector.push_back(*iter);

            return resultVector;
        }
    };
}
namespace IntersectionOfTwoArrays1{

    class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

            set<int> record(nums1.begin(),nums1.end());
//            for(int i=0;i<nums1.size();i++)
//                record.insert(nums1[i]);

            set<int> result;

            for(int i=0;i<nums2.size();i++){
                if(record.find(nums2[i])!=record.end())
                    result.insert(nums2[i]);
            }

            vector<int> resultVector(result.begin(),result.end());
//            vector<int> resultVector;
//            for(set<int>::iterator iter=result.begin();iter!=result.end();iter++)
//                resultVector.push_back(*iter);

            return resultVector;
        }
    };
}



#endif //USINGHASHTABLE_INTERSECTION_OF_TWO_ARRAYS_H
