/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isEqual(TreeNode* l,TreeNode* r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        if(l->val!=r->val) return false;
        return isEqual(l->left,r->right) && isEqual(l->right,r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isEqual(root->left,root->right);
    }
};
// @lc code=end

