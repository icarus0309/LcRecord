/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {

    }
};
// @lc code=end


/*
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        //stk.push(cur);
        while(cur || !stk.empty()) {
            while(cur) {     
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;  
            //这里的思想是：到了最左边的右边节点如果存在那就是视作中间节点，
            //如果不存在，那就返回到上一个中间节点，录进去之后再到右边节点
        }
        return res;
*/

