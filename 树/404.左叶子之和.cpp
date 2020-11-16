/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        //if(!root->left) return 0;
        if(root->left && !root->left->left && !root->left->right)
            res+=root->left->val;
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return res;
    }
};

// @lc code=end

