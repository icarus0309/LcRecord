/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len,-1);
        stack<int> stk;
        for(int i=0; i<2*len-1; i++) {
            while(!stk.empty() && nums[i%len]>nums[stk.top()]) {
                res[stk.top()] = nums[i%len];
                stk.pop();
            }
            stk.push(i%len);
        }
        return res;
    }
};
// @lc code=end

