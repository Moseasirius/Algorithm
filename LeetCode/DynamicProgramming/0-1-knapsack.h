//
// Created by mozhenhai on 2021/8/15.
//

#ifndef DYNAMICPROGRAMMING_0_1_KNAPSACK_H
#define DYNAMICPROGRAMMING_0_1_KNAPSACK_H
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
/// 背包问题
/// 记忆化搜索
/// 时间复杂度: O(n * C) 其中n为物品个数; C为背包容积
/// 空间复杂度: O(n * C)

namespace Knapsack01I{

    class Knapsack01{

    private:
        vector<vector<int>> memo;
        //用 [0..index]的物品，填充容积为c的背包的最大价值
        int bestValue(const vector<int> &w,const vector<int> &v,int  index,int c){
            if(index <0||c<=0)
                return 0;
            if(memo[index][c]!=-1)
                return  memo[index][c];
            int res = bestValue(w,v,index-1,c);
            if(c>=w[index])
                res = max(res,v[index]+ bestValue(w,v,index-1,c-w[index]));
            memo[index][c] = res;
            return res;

        }

    public:
        int knapsack01(const vector<int &w,const vector<int> &v, int index,int C){

            int n=w.size();
            memo = vector<vector<int>>(n,vector<int>(C+1,-1));

            return bestValue(w,v,n-1,C);
        }
    };
}

/// 背包问题
/// 动态规划
/// 时间复杂度: O(n * C) 其中n为物品个数; C为背包容积
/// 空间复杂度: O(n * C)
namespace Knapsack01II {

    class Knapsack01{
    public:
        int knapsack01(const vector<int &w,const vector<int> &v, int index,int C){

            assert(w.size()==v.size());

            int n=w.size();
            if(n==0){
                return 0;
            }
            vector<vector<int>> memo = vector<vector<int>>(n,vector<int>(C+1,-1));
            for(int j=0;j<=c;j++){
                memo[0][j] = (j>w[0]?v[0]:0);

            }
            for(int i=0;i<n;i++){
                for(int j=0;j<=C;j++){
                    memo[i][j] = memo[i-1][j];
                    if(j>= w[i]){
                        memo[i][j] = max(memo[i][j],v[i]+memo[i-1][j]);
                    }
                }
            }
            return memo[n-1][C];
        }




        };
}
#endif //DYNAMICPROGRAMMING_0_1_KNAPSACK_H
