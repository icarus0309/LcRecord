/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        giveVal(root,res,0);
        return res;
    }

    void giveVal(TreeNode* root,vector<vector<int>>& res,int level) {        
        if(!root) return;
        if(res.size() <= level)
            res.push_back(vector<int>());
        res[level].push_back(root->val);
        giveVal(root->left,res,level+1);
        giveVal(root->right,res,level+1);
    }
};
// @lc code=end

