/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head) return false;
    struct ListNode* p = head, *q = head->next;
    while(p!=NULL && q!=NULL && q->next!=NULL){
        if(p == q)
            return true;
        p = p->next;
        q = q->next->next;
    }
    return false;
}

// @lc code=end

