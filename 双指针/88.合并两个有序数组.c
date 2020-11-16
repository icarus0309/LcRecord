/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

// @lc code=start

//牛逼！！！！！！！
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index_1 = m-1, index_2 = n-1;
    int index_merge = m+n-1;
    while(index_1>=0 || index_2 >=0){
        if(index_1<0){
            nums1[index_merge--] = nums2[index_2--];
        }else if(index_2<0){
            nums1[index_merge--] = nums1[index_1--];
        }else if(nums1[index_1] > nums2[index_2]){
            nums1[index_merge--] = nums1[index_1--];
        }else nums1[index_merge--] = nums2[index_2--];
    }
}


// @lc code=end

