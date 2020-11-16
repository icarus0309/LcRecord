/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* cur = root;
        map<int,int> mp;
        stack<TreeNode*> stk;
        while(cur || !stk.empty()) {
            while(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            mp[cur->val]++;
            cur = cur->right;
        }
        int maxnum = mp[root->val];
        map<int,int>::iterator it;
        it = mp.begin();
        while(it!=mp.end()) {
            if(it->second > maxnum)
                maxnum = it->second;
            it++;
        }
        it = mp.begin();
        while(it!=mp.end()) {
            if(it->second == maxnum)
                res.push_back(it->first);
            it++;
        }        
        return res;
    }
};
// @lc code=end

