/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums) {
            mp[i]++;
        }
        int res = 0;
        for(auto i:mp) {
            if(mp.count(i.first+1)) //这一行为什么要加上呢？
                res = max(res,i.second + mp[i.first+1]);
        }
        return res;
    }
};
// @lc code=end

