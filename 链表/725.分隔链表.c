/*
 * @lc app=leetcode.cn id=725 lang=c
 *
 * [725] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct ListNode STR_NODE;
typedef struct ListNode* PSTR_NODE;
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){  
    PSTR_NODE p = root;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    p = root;
    int remd = len%k, div = len/k;
    int* arr = (int*)malloc(sizeof(int)*k);
    PSTR_NODE ptmp;
    PSTR_NODE* res = (PSTR_NODE*)malloc(sizeof(PSTR_NODE)*k);
    int i = 0, j = 0;
    for(; i<k; i++){
        arr[i] = (remd--)>0 ? (div+1) : div;
		if(arr[i])
        	res[i] = (PSTR_NODE)malloc(sizeof(STR_NODE)*arr[i]); 
    } //注意：每次给二维数组在堆开辟空间时，开辟了一维后要立即开辟二维
    for(i=0; i<k; i++){
		if(p){
			res[i][0].val = p->val;
			ptmp = res[i];
			p = p->next;
			for(j=1; j<arr[i]; j++){
				res[i][j].val = p->val;
				ptmp->next = (res[i]+j);
				ptmp = (res[i]+j);
				p = p->next;
			}
			ptmp->next = NULL;
		}else res[i]=NULL;
    }
	*returnSize = k;
    return res;
}



// @lc code=end

