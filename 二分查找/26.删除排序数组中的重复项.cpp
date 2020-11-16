/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int i=1,j=1;
        for(; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

// @lc code=end

