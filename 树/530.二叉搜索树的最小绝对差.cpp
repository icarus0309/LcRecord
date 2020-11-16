/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    //先用中序遍历出所有值存放到vector里，然后比较每相邻两个的差值绝对值
public:
    vector<int> nums;
    int getMinimumDifference(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        while(cur || !stk.empty()) {
            while(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            nums.push_back(cur->val);
            cur = cur->right;
        }
        if(nums.size() < 2) return -1;
        int resmin = abs(nums[1]-nums[0]);
        for(int i=0; i<nums.size()-1; i++) {
            int  j = i+1;
            int tmp = abs(nums[j]-nums[i]);
            if(tmp < resmin)
                resmin = tmp;
        }
        return resmin;
    }
};
// @lc code=end

