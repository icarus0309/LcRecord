/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
//这一题的动态规划也太骚了
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        if(num==0) return res;
        int k = 1;
        for(int i=1; i<=num; i++) {
            k = i>=(2*k) ? 2*k : k;
            res[i] = 1+res[i-k];
        }
        return res;
    }
};
// @lc code=end

