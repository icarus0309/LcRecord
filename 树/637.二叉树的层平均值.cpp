/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    //改进点在于1.避开longlong，2.少定义一个甚至两个vec
    vector<int> each_num;
    vector<long long int> each_sum; 
    vector<double> averageOfLevels(TreeNode* root) {
        int level = 1;
        initNumSum(root,level);
        vector<double> res;
        int levels = each_num.size();
        for(int i=0; i<levels; i++){
            res.push_back(each_sum[i]/(double)each_num[i]);
        }
        return res;
    }

    void initNumSum(TreeNode* root,int level) {
        if(!root) return;
        int ls = each_num.size();
        if(ls>=level){
            each_num[level-1]++;
            each_sum[level-1]+=root->val;
        } else {
            each_num.push_back(1);
            each_sum.push_back(root->val);
        } 
        initNumSum(root->left,level+1);
        initNumSum(root->right,level+1);
    }
};
// @lc code=end

