/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 */

// @lc code=start

//时间
//我觉得下面这就是最优解了
void swap(int* nums, int a, int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void sortColors(int* nums, int numsSize){
    int l = 0, r = numsSize, index = -1;
    while(l<r){
        if(nums[l]==0){
            swap(nums,l++,++index);
        }else if(nums[l]==2){
            swap(nums,l,--r);
        }else l++;
    }
}

// @lc code=end

