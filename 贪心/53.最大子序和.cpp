/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    //动态规划解法
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxans = nums[0];
        for(int& i:nums){
            pre = max(pre+i,i);
            maxans = max(maxans,pre);
        }
        return maxans;
    }

    /*
        //贪心解法
        int ans = nums[0];
        int sum = 0;
        for(int num: nums) {
            if(sum > 0) {
                sum += num;
            } else {
                sum = num;
            }
            ans = max(ans, sum);
        }
        return ans;

    */

};

// @lc code=end

