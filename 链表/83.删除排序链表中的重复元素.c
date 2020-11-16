/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
//我的方案
struct ListNode* findNext(struct ListNode* p,int* arr,int cont){
	//宗旨就是把合格的下一个节点传输个p
	if(!p->next) return NULL;
	struct ListNode* pnext = p->next;
	for(int i=0;i<cont;i++){
		if(p->next->val == arr[i]){
			pnext = findNext(p->next,arr,cont);
		}
	}
	return pnext;
}


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head) return NULL;   
    int arr[1024]={0}, i=0, cont=1;
    arr[0] = head->val;
    struct ListNode *p = head, *pnext = NULL;
    while(p->next){
		pnext = p->next;
		p->next = findNext(p,arr,cont);
	    if(p->next){
            arr[cont] = p->next->val;
            cont++;
        }
        p = p->next!=NULL?p->next:p;//问题出在我认为p->next一定是没问题的，也就是原先的p->next->next
    }
    return head;
}
//这个方法的执行效率低不要紧，因为它针对的是非排序完成的链表
*/


//这个能执行顺序链表，本质上是剔除相邻的相同节点比如113322，就成了132
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    head->next = deleteDuplicates(head->next);
    return head->val==head->next->val?head->next:head;
}

// @lc code=end

