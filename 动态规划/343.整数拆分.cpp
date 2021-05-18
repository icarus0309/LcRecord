/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if (n < 3) {
            return 1;
        }
        vector<int> f(n+1, 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2 + 1; j++) {
                f[i] = max(max(( i- j) * j, f[i - j] * j), f[i]);
            }
        }
        return f[n];
    }
};
// @lc code=end

