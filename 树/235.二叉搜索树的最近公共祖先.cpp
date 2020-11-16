/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;
        while (root) {
            int curval = root->val;
            if (curval > p->val && curval > qval )
                root = root->left;
            else if (curval < p->val && curval < qval )
                root = root->right;
            else return root;
        }
        return NULL;
    }
};
// @lc code=end

