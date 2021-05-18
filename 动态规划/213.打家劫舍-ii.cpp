/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int dynCont(vector<int>& nums, int start, int end)
    {
        int first = nums[start]; // second = (end <= start ? first : nums[start + 1]);
        int second = max(nums[start + 1], first);
        for (int i = start + 2; i <= end; i++) {
            int temp = first;
            first = second;
            second = max(temp + nums[i], second);
        }
        return second;
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        return max(dynCont(nums, 0, n - 2), dynCont(nums, 1, n - 1));
    }
};
// @lc code=end

