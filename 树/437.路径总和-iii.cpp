/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
private:
    int x = 0;
    int i = 0;
public:
    //但凡遇到这种，任意一个节点都可以的，就要考虑一下私有成员了
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        depth(root,sum,x);
        return i;
    }
    void depth(TreeNode* root, int sum, int z) {
        if(!root)
            return ;
        z += root->val;
        if(z==sum)
            i++;
        depth(root->left,sum,z);
        depth(root->right,sum,z);   
        //好阴险啊。。。     
    }
};

// @lc code=end

