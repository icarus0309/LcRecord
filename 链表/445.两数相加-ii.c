/*
 * @lc app=leetcode.cn id=445 lang=c
 *
 * [445] 两数相加 II
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

struct ListNode* getReserve(PSTR_NODE tar){
    PSTR_NODE p = tar;
    PSTR_NODE pre = (PSTR_NODE)malloc(sizeof(STR_NODE));
    pre->next = NULL;
    while(p){
        PSTR_NODE tmp = (PSTR_NODE)malloc(sizeof(STR_NODE));
        tmp->val = p->val;
        tmp->next = pre->next;
        pre->next = tmp;
        p = p->next;
    }
    PSTR_NODE res = pre->next;
    free(pre);
    return res;
}

PSTR_NODE addList(PSTR_NODE l1,PSTR_NODE l2){
    if(!l1) return l2;
    if(!l2) return l1;
    int cur = 0;
    PSTR_NODE pre = (PSTR_NODE)malloc(sizeof(STR_NODE));
    pre->next = NULL;
    while(l1 && l2){
        PSTR_NODE tmp = (PSTR_NODE)malloc(sizeof(STR_NODE));
        tmp->val = l1->val + l2->val + cur;
        if(tmp->val>9){
            tmp->val %= 10;
            cur = 1;
        }else cur = 0;
        tmp->next = pre->next;
        pre->next = tmp;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1){
        PSTR_NODE tmp = (PSTR_NODE)malloc(sizeof(STR_NODE));
        tmp->val = l1->val + cur;
        if(tmp->val>9){
            tmp->val %= 10;
            cur = 1;
        }else cur = 0;
        tmp->next = pre->next;
        pre->next = tmp;
        l1 = l1->next;
    }
    while(l2){
        PSTR_NODE tmp = (PSTR_NODE)malloc(sizeof(STR_NODE));
        tmp->val = l2->val + cur;
        if(tmp->val>9){
            tmp->val %= 10;
            cur = 1;
        }else cur = 0;
        tmp->next = pre->next;
        pre->next = tmp;
        l2 = l2->next;
    }
    if(cur){
        PSTR_NODE tmp = (PSTR_NODE)malloc(sizeof(STR_NODE));
        tmp->val = 1;
        tmp->next = pre->next;
        pre->next = tmp;
    }
    PSTR_NODE res = pre->next;
    free(pre);
    return res;
}

void listShow(PSTR_NODE l){
    PSTR_NODE p = l;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
    putchar('\n');
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    PSTR_NODE re_l1 = getReserve(l1);
    PSTR_NODE re_l2 = getReserve(l2);
    PSTR_NODE _added = addList(re_l1,re_l2);
    //_added = getReserve(_added);
    return _added;
}


// @lc code=end

