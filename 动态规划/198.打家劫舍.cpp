/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        //if(n==2) return max(nums[0],nums[1]);
        int second=nums[0];
        int first = max(nums[1],nums[0]);
        for(int i=2; i<n; i++){
            int tmp = first;
            first = max(first,second+nums[i]);
            second = tmp;
        }
        return first;
    }
};
// @lc code=end

