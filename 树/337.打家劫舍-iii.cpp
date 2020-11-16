/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        auto res = dynPlan(root);
        return max(res.first,res.second);
    }

    pair<int,int> dynPlan(TreeNode* root) {
        //原来在代码段里定义临时变量不影响内存消耗啊
        //但是一想--本来就是这样，程序结束就被释放了
        if(!root)
            return {0,0};
        //pair<int,int> res;
        auto a = dynPlan(root->left);
        auto b = dynPlan(root->right);
        //res.first = root->val + a.second + b.second;
        //res.second = max(a.first, a.second) + max(b.first,b.second);
        return {root->val + a.second + b.second,\
                max(a.first, a.second) + max(b.first,b.second)};
    }
};
// @lc code=end

