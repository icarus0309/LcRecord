/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
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

int minDepth(struct TreeNode* root){
    if(!root) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return 1 + (left<right? left : right);
}



bool isBalanced(struct TreeNode* root){
    int max_res = maxDepth(root);
    int min_res = minDepth(root);
    if(max_res - min_res <= 1)
        return true;
    else 
        return false;
        
}


// @lc code=end

