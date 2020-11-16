/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + (left>right? left : right);
}


// @lc code=end

