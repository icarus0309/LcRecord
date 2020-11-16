/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode STR_NODE;
typedef struct ListNode* PSTR_NODE;

PSTR_NODE reverse(PSTR_NODE head, PSTR_NODE node){
    PSTR_NODE p = head, tmp;
    PSTR_NODE res = (PSTR_NODE)malloc(sizeof(STR_NODE));
    res->next = NULL;
    while(p != node->next){        
        tmp = (PSTR_NODE)malloc(sizeof(STR_NODE));
        tmp->val = p->val;
        tmp->next = res->next;
        res->next = tmp;
        p = p->next;
    }
    free(res);
    return tmp;
}

bool isPalindrome(struct ListNode* head){
    if(!head) return true;
    PSTR_NODE p = head, q = head;
    while(q!=NULL && q->next != NULL){
        p = p->next;
        q = q->next->next;
    }
    //如果q为NULL则舍弃p反转的第一个
    PSTR_NODE pr = reverse(head,p);
    if(!q) pr = pr->next;
    while(p){
        if(p->val != pr->val) return false;
        p  = p->next;
        pr = pr->next;
    }
    return true;
}


// @lc code=end

