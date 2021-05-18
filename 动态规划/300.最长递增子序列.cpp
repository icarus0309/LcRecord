/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(2, 0);
        f[1] = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int n = f.size();
            if (nums[i] > f[n - 1]) {
                f.push_back(nums[i]);
            } else {
                int start = 1, end = n - 1, pos = 0;
                while (start <= end) {
                    int mid = (start + end) >> 1;
                    if (nums[i] <= f[mid]) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                        pos = mid;
                    }
                }
                f[pos + 1] = nums[i];
            }
        }
        return f.size() - 1;
    }
};


// @lc code=end

