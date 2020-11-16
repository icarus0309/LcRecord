/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(head!=NULL && k>1){
        int len = 0,i=0,j=0;
        struct ListNode *p = head, *q = NULL, *tmp = NULL;
		struct ListNode *next_head_tmp=NULL, *head_tmp = malloc(sizeof(struct ListNode));

        while(p!=NULL){
            len++;
            p=p->next;
        }
        p = head;
        for(i=k-1; i<len; i+=k){
			next_head_tmp = p;
			
			q = p->next;
			for(j=0;j<k-1;j++){
				tmp = p;
				p = q;
				q = q->next;
				p->next = tmp;
            }
			head_tmp->next = p;
			head_tmp = next_head_tmp;
			head = i==(k-1)?p:head;
			p = q;

        }
		head_tmp->next = p;

    }
    return head;
}


// @lc code=end

