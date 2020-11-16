/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {

    }
};
// @lc code=end

/*
        //dfs(root);
        //return res;    
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        //stk.push(cur);
        while(cur || !stk.empty()) {
            while(cur) {     
                stk.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->right;
        }
        return res;
*/

/*
    void dfs(TreeNode* root) {
        if(!root) return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
*/