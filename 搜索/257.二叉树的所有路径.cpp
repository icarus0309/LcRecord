/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr)
            return res;
        _binaryTreePaths(root, res, "");
        return res;
    }

    void _binaryTreePaths(TreeNode* node, vector<string>& res, string p) {
        string cur = to_string(node->val);
        p = p + cur;
        if(node->left == nullptr && node->right == nullptr) {
            res.push_back(p);
            return;
        }
        if(node->left)
            _binaryTreePaths(node->left, res, p + "->");
        if(node->right)
            _binaryTreePaths(node->right, res, p + "->");
    }
};
// @lc code=end

