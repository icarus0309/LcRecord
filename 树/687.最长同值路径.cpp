/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    //int max_res;//在这里定义的话浪费时间
    int help(TreeNode* root,int* max_res) {
        if(!root) return 0;
        int left = help(root->left,max_res);
        int right = help(root->right,max_res);
        int left_th = 0;
        int right_th =0;
        if(root->left && root->left->val==root->val)//只有相等才可以为我所用
            left_th = left+1;//加的一代表当前节点自己
        if(root->right&& root->right->val == root->val)
            right_th = right+1;
        *max_res = max(*max_res,left_th+right_th);//不需要减一，因为这是路径而不是节点
        //尤其要注意，返回值和当前左右之和不是一码事，因为返回去的只能是一条线，不可以出现倒V字型
        return max(right_th,left_th);//作用只需要一条就好了
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int max_res = 0;
        help(root,&max_res);
        return max_res;
    }
};
// @lc code=end

