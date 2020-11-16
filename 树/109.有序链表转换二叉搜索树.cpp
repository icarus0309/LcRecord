/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
    int getListSize(ListNode* head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    TreeNode* buildTree(ListNode* head,int l,int r) {
        if(l>r) return nullptr;
        int mid = (l+r)>>1;
        //cout << mid << "," << r << endl;
        ListNode* midnode = head;
        for(int i=0;i<mid;i++)
            midnode = midnode->next;
        TreeNode* root = new TreeNode(midnode->val);
        root->left = buildTree(head,l,mid-1);
        root->right = buildTree(head,mid+1,r);
        return root;
    }

*/


/*
    TreeNode* buildTree(vector<int>& v,int l,int r) {
        if(l>=r) return nullptr;
        int mid = (l+r)>>1;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = buildTree(v,l,mid);
        root->right = buildTree(v,mid+1,r);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        TreeNode* root = buildTree(v,0,v.size());
        return root;
    }
*/
//这里划分条件不一样，出来的树也不一样，比如“左-中-右”和“左-右”
class Solution {
public:
    TreeNode* buildTree(ListNode* head, ListNode* tail) {
        if(head==tail) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=tail && fast->next!=tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildTree(head,slow);
        root->right = buildTree(slow->next,tail);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = buildTree(head,nullptr);
        return root;
    }
};

// @lc code=end

