//
// Created by mozhenhai on 2021/9/4.
//

#ifndef RECURIONANDBACKSTRACKING_SUBSETS_H
#define RECURIONANDBACKSTRACKING_SUBSETS_H
#include <iostream>
#include <vector>
using namespace std;

namespace  Subsets1{
    class Solution {
    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtrace(vector<int> &nums,int index){
            if(index==nums.size()) return;
            for(int i=index;i<nums.size();i++){
                path.push_back(nums[i]);
                result.push_back(path);
                backtrace(nums,i+1);
                path.pop_back();
            }

        }

    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            result.clear();
            path.clear();
            result.push_back(path);
            backtrace(nums,0);
            return result;

        }
    };
}
namespace Subsets2{
    class Solution {
    private:
        vector<vector<int>> result;
        vector<int> temp;

    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            result.clear();
            temp.clear();
            result.push_back(vector<int> {});
            for(int i=0;i<nums.size();i++){
                int sz = result.size();
                for(int j=0;j<sz;j++){
                    temp = result[j];
                    temp.push_back(nums[i]);
                    result.push_back(temp);
                }
            }
            return result;

        }
    };
}
void testSubsets(){
    int arr [] = {1,2,3};
    vector<int> nums(arr,arr+sizeof (arr)/sizeof (int));
    vector<vector<int>> res = Subsets1::Solution().subsets(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}
#endif //RECURIONANDBACKSTRACKING_SUBSETS_H
