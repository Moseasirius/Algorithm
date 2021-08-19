//
// Created by mozhenhai on 2021/8/15.
//

#ifndef RECURIONANDBACKSTRACKING_PERMUTATIONS_H
#define RECURIONANDBACKSTRACKING_PERMUTATIONS_H

/// 46. Permutations
/// https://leetcode.com/problems/permutations/description/
/// 时间复杂度: O(n^n)
/// 空间复杂度: O(n)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace permutations {
    class Solution {

    private:
        vector<vector<int>> res;
        vector<bool> used;

        //int index 表示现在正在处理第几个元素 vector<int>& p 表示找到的一个排列
        //p中保存了一个有index个元素的排列
        //向这个排列的末尾添加第index+1 个元素，获得一个有index+1个元素的排列
        void generatePermutations(const vector<int> &nums, int index, vector<int> &p) {

            if (index == nums.size()) {

                for (int i:p)
                    cout << i << " ";
                cout << endl;

                res.push_back(p);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {


                    p.push_back(nums[i]);

                    cout << "push_back:  " << nums[i] << endl;
                    used[i] = true;
                    generatePermutations(nums, index + 1, p);

                    cout << "pop.back:  " << p.back() << endl;
                    p.pop_back();
                    used[i] = false;
                }
            }
            return;
        }

    public:
        vector<vector<int>> permute(vector<int> &nums) {
            res.clear();
            if (nums.size() == 0)
                return res;
            used = vector<bool>(nums.size(), false);
            vector<int> p;
            generatePermutations(nums, 0, p);

            return res;
        }

    };
}

void permutationsTest() {
    vector<int> array;
    int n = 3;
    for (int i = 1; i <= n; i++) {
        array.push_back(i);
    }
    vector<vector<int>> res = permutations::Solution().permute(array);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {

            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}
void testSet(){
    int myInts[] = {1, 11, 1, 2, 3};
    set<int> mySet(myInts, myInts + 5);//set with 5 ints
    for(int i=0;i<10;i++){
        mySet.insert(i);
    }
    set<int>::iterator it;
    cout << "mySet contains:";
    for (it = mySet.begin(); it != mySet.end(); it++)
        cout << " " << *it;
}

#endif //RECURIONANDBACKSTRACKING_PERMUTATIONS_H
