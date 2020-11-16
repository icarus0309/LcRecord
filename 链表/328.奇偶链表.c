/*
 * @lc app=leetcode.cn id=328 lang=c
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(!head) return NULL;
    if(!(head->next)) return head;
    struct ListNode* p =head , *q = head->next;
    struct ListNode* oddhead = q;
    while(p->next && q->next){
        p->next = p->next->next;
        q->next = q->next->next;
        p = p->next;
        q = q->next;
    }
    p->next = oddhead;
    return head;
}
// @lc code=end

