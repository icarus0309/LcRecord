/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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

/*
public int kthSmallest(TreeNode root, int k) {
    int leftCnt = count(root.left);
    if (leftCnt == k - 1) return root.val;
    if (leftCnt > k - 1) return kthSmallest(root.left, k);
    return kthSmallest(root.right, k - leftCnt - 1);
}
private int count(TreeNode node) {
    if (node == null) return 0;
    return 1 + count(node.left) + count(node.right);
}
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftcnt = count(root->left);
        if(leftcnt == k-1) return root->val;
        if(leftcnt > k-1) return kthSmallest(root->left,k);
        return kthSmallest(root->right,k-leftcnt-1);
    }
    int count(TreeNode* root) {
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};

// @lc code=end

/*
        int count = 0;
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        while(cur || !stk.empty()) {
                while(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if(++count == k)
                break;
            cur = cur->right;
        }
        return cur->val;
*/