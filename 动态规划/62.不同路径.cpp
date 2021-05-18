/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        vector<vector<int>> block(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            block[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            block[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                block[i][j] = block[i - 1][j] + block[i][j - 1];
            }
        }
        return block[m - 1][n - 1];
    }
};
// @lc code=end

