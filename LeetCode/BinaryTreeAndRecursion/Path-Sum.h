//
// Created by mozhenhai on 2021/8/15.
//

#ifndef BINARYTREEANDRECURSION_PATH_SUM_H
#define BINARYTREEANDRECURSION_PATH_SUM_H

/// 112. Path Sum
/// https://leetcode.com/problems/path-sum/description/
/// 时间复杂度: O(n), n为树的节点个数
/// 空间复杂度: O(h), h为树的高度

// Definition for a binary tree node.*
namespace PathSum{
    struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {

            if(root==nullptr)
                return false;
            if(root->left==nullptr&&root->right==nullptr)
                return targetSum==root->val;
            return hasPathSum(root->left,targetSum-root->val)||
                   hasPathSum(root->right,targetSum-root->val);

        }
    };

}
 s
#endif //BINARYTREEANDRECURSION_PATH_SUM_H
