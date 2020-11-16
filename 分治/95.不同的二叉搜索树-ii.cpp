/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return giveNode(1,n);        
    }
    //返回值类型一样，可以重载的
    vector<TreeNode*> giveNode(int begin, int end) {
        if(begin>end) return {nullptr};
        vector<TreeNode*> alltrees;

        for(int i=begin; i<=end; i++) {
            vector<TreeNode*> leftrees = giveNode(begin,i-1); 
            //关键是在这两步的理解上，后面都还好
            vector<TreeNode*> rightrees = giveNode(i+1,end);
            for(auto& left:leftrees) {
                for(auto& right:rightrees) {
                    TreeNode* cur_node = new TreeNode(i);
                    cur_node->left = left;
                    cur_node->right = right;
                    alltrees.push_back(cur_node);
                }
            }
        }
        return alltrees;
    }
};
// @lc code=end

