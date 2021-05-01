/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> iter_ret;

    void backTrace(vector<int>& nums, int pos)
    {
        ret.push_back(vector<int>(iter_ret));
        int i = pos;
        while (i < nums.size()) {
            iter_ret.push_back(nums[i]);
            backTrace(nums, i+1);
            iter_ret.pop_back();
            while(++i < nums.size() && nums[i] == nums[i-1]);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        ret.clear();
        iter_ret.clear();
        sort(nums.begin(), nums.end());
        backTrace(nums, 0);
        return ret;
    }
};

// @lc code=end

