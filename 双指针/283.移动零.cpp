/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        for(; i<nums.size(); i++){
            if(nums[i]!=0){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                ++j;
            }
        }
    }
};
// @lc code=end

