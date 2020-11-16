/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* p;
        while(!que.empty()) {
            p = que.front();
            que.pop();
            if(p->right)
                que.push(p->right);
            if(p->left)
                que.push(p->left);
        }
        return p->val;
    }
};

// @lc code=end

