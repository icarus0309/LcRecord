/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode* root, int k) {
        map<int,int> mp;
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        while(cur || !stk.empty()) {
            while(cur) {
                stk.push(cur);            
                mp[cur->val] = 1;
                if(mp[k - cur->val]==1 && 2*cur->val!=k)
                    return true;
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->right;
        }
        return false;
    }
};

// @lc code=end

/*
    vector<int> tmp;
    void dfs(TreeNode* root){ // dfs遍历构建一个vector
        if(!root) return;
        dfs(root->left);
        tmp.push_back(root->val);
        dfs(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k){
        if(!root) return false;// 这一句加不加都能过
        dfs(root);
        for(int i = 0; i < tmp.size() - 1; i++){// 双指针法求两数之和
            for(int j = tmp.size() - 1; j > i; j--){ // j从后开始，方便快速筛选不满足条件的解
                if(tmp[i] + tmp[j] < k) break;
                if(tmp[i] + tmp[j] == k) return true;
            }
        }
        return false;
    }
*/

/*
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        map<int,int> mp;
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        while(cur || !stk.empty()) {
            while(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            mp[cur->val] = 1;
            if(mp[k - cur->val]==1 && 2*cur->val!=k)
                return true;
            cur = cur->right;
        }
        return false;
    }
*/

