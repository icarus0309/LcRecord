/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* trimBST(TreeNode* root, int L, int R)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (root->val > R)
        {
            return trimBST(root->left, L, R); //只处理左子树，相当于剪掉了root及其右子树
        }

        if (root->val < L)
        {
            return trimBST(root->right, L, R); //只处理右子树，相当于剪掉了root及其左子树
        } 

        // root->val >= L && root->val <= R

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);

        return root;
    }
};
// @lc code=end

