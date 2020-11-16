/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //先找到对应的节点
    if(head==NULL||n==0) return head;
    struct ListNode *phead = malloc(sizeof(struct ListNode));
    phead->next = head;
    struct ListNode *p = head, *pn = NULL;
    for(;n>0;n--){
        if(!p) return head;
        p = p->next;
    }
    if(!p) return head->next;
    pn = phead;
    while(p){
        p = p->next;
        pn = pn->next;
    }
    pn->next = pn->next->next;
    free(phead);
    return head;
}


// @lc code=end

