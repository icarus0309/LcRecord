/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL|| headB==NULL)
        return NULL;
    struct ListNode *pa = headA, *pb = headB;
    while(pa!=pb){
        pa = pa!=NULL?pa->next:headB;
        pb = pb!=NULL?pb->next:headA;
    }
    pb = NULL;
    free(pb);
    return pa;
}
