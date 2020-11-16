/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL)
            return false;
        if(isEqual(s,t))
            return true;
        return isSubtree(s->left,t)||isSubtree(s->right,t);
    }//没事就别瞎定义新的变量了

    bool isEqual(TreeNode* tmps, TreeNode* t){
        if(tmps==NULL && t==NULL)
            return true;
        if(tmps==NULL || t==NULL)
            return false;
        if(tmps->val != t->val)
            return false;
        return ( isEqual(tmps->left,t->left) &&\
                 isEqual(tmps->right,t->right) );
    }
};
// @lc code=end

