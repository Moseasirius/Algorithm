//
// Created by mozhenhai on 2021/8/18.
//

#ifndef USINGHASHTABLE_TEST_H
#define USINGHASHTABLE_TEST_H
#include "Intersection-of-Two-Arrays.h"

void IntersectionOfTwoArraysTest(){

    int nums1 [] = {4,9,5};
    int nums2 [] ={9,4,9,8,4};

    vector<int> numsV1(nums1,nums1+sizeof(nums1)/sizeof(int));
    vector<int> numsV2(nums2,nums2+sizeof(nums2)/sizeof(int));

    vector<int> res = IntersectionOfTwoArrays::Solution().intersection(numsV1,numsV2);

    for(int i:res){
        cout<<i<<" ";
    }

}
#endif //USINGHASHTABLE_TEST_H
