/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 0;
    if(!numbers || numbersSize == 1) return NULL;
    int* res = (int*)malloc(sizeof(int)*2);
    res[0] = 1;
    res[1] = numbersSize;
    while(*(numbers+res[0]-1)+*(numbers+res[1]-1)!=target && res[0]<res[1]){
        if(*(numbers+res[0]-1)+*(numbers+res[1]-1)>target)
            res[1]--;
        else if(*(numbers+res[0]-1)+*(numbers+res[1]-1)<target)
            res[0]++;
    }
    if(res[0]==res[1]) return NULL;
    *returnSize = 2;
    return res;
}


// @lc code=end

