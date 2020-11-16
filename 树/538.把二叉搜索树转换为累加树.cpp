/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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

/*
        if (root == null) return root;
        convertBST(root.right);
        root.val += add;
        add = root.val;
        convertBST(root.left);
        return root;
*/
class Solution {
public:
    int add;
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        convertBST(root->right);//果然递归的本质是压栈啊
        root->val += add;
        add = root->val;
        convertBST(root->left);
        return root;
        /*
        stack<TreeNode*> stk;
        int last_val = 0;
        TreeNode* cur = root;
        while(cur || !stk.empty()) {
            while(cur) {
                stk.push(cur);
                cur = cur->right;
            }
            cur = stk.top();
            stk.pop();
            cur->val += last_val;
            last_val = cur->val;
            cur = cur->left;
        }
        return root;*/
    }
};

// @lc code=end

