/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
//看来遇到二叉树，，，想要快还是得用迭代
//不对，我才我刚刚应该是重复调用了
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* tmp = stk.top();
            res.push_back(tmp->val);
            stk.pop();
            for(int i=tmp->children.size()-1; i>=0; i--){
                stk.push(tmp->children[i]);
            }
        }
        return res;     
    }
};
// @lc code=end

