/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        vector<int> res(n+1,0);
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;
        for(int i=3; i<=n; i++) {
            res[i] = res[i-1]+res[i-2];
        }
        return res[n];
    }
};

// @lc code=end

