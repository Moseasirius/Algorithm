//
// Created by mozhenhai on 2021/8/15.
//

#ifndef RECURIONANDBACKSTRACKING_COMBINATIONS_H
#define RECURIONANDBACKSTRACKING_COMBINATIONS_H

/// 77. Combinations
/// https://leetcode.com/problems/combinations/description/
/// 时间复杂度: O(n^k)
/// 空间复杂度: O(k)
#include <iostream>
#include <vector>

using namespace std;
namespace Combinations{
    class Solution {

    private:
        vector<vector<int>> res;

        void generateCombine(int n,int k,int start,vector<int> &c){
            if(c.size()==k){
                res.push_back(c);
                return;
            }
            for(int i=start;i<=n-(k-c.size())+1;i++){

                c.push_back(i);
                generateCombine(n,k,i+1,c);
                c.pop_back();

            }
            return;
        }
    public:
        vector<vector<int>> combine(int n, int k) {
            res.clear();
            if(k<=0||n<=0||k>n)
                return res;
            vector<int>c ;
            generateCombine(n,k,1,c);

            return res;
        }
    };
}
void testCombinations(){
    int n=4,k=2;
    vector<vector<int>> res =Combinations::Solution().combine(n,k);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}
#endif //RECURIONANDBACKSTRACKING_COMBINATIONS_H
