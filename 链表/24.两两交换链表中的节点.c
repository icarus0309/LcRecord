/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(!head || !head->next) return head;
    struct ListNode *phead = malloc(sizeof(struct ListNode));
    struct ListNode *tmp = NULL, *acc = NULL;
    phead->next = head;
    acc = phead;
    while(phead->next!=NULL && phead->next->next!=NULL){
        tmp = phead->next->next;
        phead->next->next = tmp->next;
        tmp->next = phead->next;
        phead->next = tmp;
        phead = tmp->next;
    }
    return acc->next;
    
}


// @lc code=end

