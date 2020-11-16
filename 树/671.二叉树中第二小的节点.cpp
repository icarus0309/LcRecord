/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue(TreeNode* root) {
        auto res = secSearch(root);
        if(res.first == res.second) return -1;
        return res.second;
    }
    //根据题意写的
    int findmin_3(int a,int b,int c,int m_val){
        int min = a<b?(a<c?a:c):(b<c?b:c);
        int max = a>b?(a>c?a:c):(b>c?b:c);
        int mid = a-min-max+b+c;
        if(m_val != min) return min;
        else if(m_val != mid) return mid;
        else return max;        
    }
    pair<int,int> secSearch(TreeNode* root) {
        if(!root->left && !root->right) {//只要有一个为空
            return {root->val, root->val};
        }
        int f_min=0, s_min=0;
        auto a = secSearch(root->left);
        auto b = secSearch(root->right);
        int tmp_f_min = min(a.first,b.first);
        f_min = min(tmp_f_min,root->val);
        if(f_min == a.first) {
            if(a.second==f_min && b.second==f_min && root->val==f_min) s_min = f_min;
            else {
                int tmp = b.first == f_min? b.second : b.first;
                s_min = findmin_3(a.second,tmp,root->val,f_min);
            }
        } else if (f_min == b.first) { //所以他自己的second呢？--这里我不加b.second竟然能够通过
            if(a.second==f_min && b.second==f_min && root->val==f_min) s_min = f_min;
            else {
                int tmp = a.first == f_min? a.second : a.first;
                s_min = findmin_3(b.second,tmp,root->val,f_min);
            }
        } else s_min = tmp_f_min;
        return {f_min,s_min};
    }
};
// @lc code=end

