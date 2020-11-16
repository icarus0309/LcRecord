/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        return !root ? true : (abs(depth(root->right)-depth(root->left))<=1)&&\
                                (isBalanced(root->right))&&\
                                (isBalanced(root->left));
    }

    int depth(TreeNode* root){
        return !root ? 0 : max(depth(root->left),depth(root->right))+1;
    }
};

// @lc code=end

