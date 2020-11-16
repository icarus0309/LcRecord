/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution {
//将结合律运用的很妙啊，而且这个初始值赋值很高明
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for(int i=0; i<nums.size(); i++) {
            res = res^i^nums[i];
        }
        return res;
    }
};
// @lc code=end

