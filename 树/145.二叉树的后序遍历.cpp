/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur || !stk.empty()) {
            while(cur) {
                stk.push(cur);
                res.push_back(cur->val);
                cur = cur->right;
            }
            cur = stk.top()->left;
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// @lc code=end



/*
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur || !stk.empty()) {
            while(cur) {
                stk.push(cur);
                res.push_back(cur->val);
                cur = cur->right;
            }
            cur = stk.top()->left;
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
*/