/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
            backTrace(nums, i + 1);
            iter_ret.pop_back();
            i++;
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        ret.clear();
        iter_ret.clear();
        backTrace(nums, 0);
        return ret;     
    }
};

// @lc code=end

