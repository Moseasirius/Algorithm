//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_MINIMUM_SIZE_SUBARRAY_SUM_H
#define USINGARRAY_MINIMUM_SIZE_SUBARRAY_SUM_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace MinimumSizeSubarray{
class Solution{

public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int l = 0 , r = -1;
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
void minSubArrayLenTest(){
    int array[] = {5,1,3,5,10,7,4,9,2,8};
    vector<int> vec(array, array + sizeof(array) / sizeof(int));

    int res;
    res = Solution().minSubArrayLen(15,vec);
    cout<<res<<endl;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}


}
#endif //USINGARRAY_MINIMUM_SIZE_SUBARRAY_SUM_H
