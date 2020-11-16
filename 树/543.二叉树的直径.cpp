/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int res;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return res;
    }

    int depth(TreeNode* root){
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        res = max(left+right,res);
        return max(left,right)+1;
    }
};
// @lc code=end

