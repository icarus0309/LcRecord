/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// 这一题不用考虑grid的冲突，反而难点在于记忆矩阵
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int dfs(vector<vector<int>>& memo, const vector<vector<int>>& mat, int i, int j) {
        // int cur_longest = 1;
        if(memo[i][j] != 0) {
            return memo[i][j];
        }
        memo[i][j]++;       // 这一步我没想到，但是非常地关键啊！！
        for(int k = 0; k < 4; k++) {
            int ne_i = i + dir[k][0], ne_j = j + dir[k][1];
            if(ne_i < 0 || ne_i > m-1 || ne_j < 0 || ne_j > n-1 || mat[i][j] >= mat[ne_i][ne_j])
                continue;
            // cur_longest = max(cur_longest, 1 + dfs(mat, ne_i, ne_j));
            memo[i][j] = max(memo[i][j], 1 + dfs(memo, mat, ne_i, ne_j));
        }        
        return memo[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0) return 0;
        n = matrix[0].size();
        int final_ret = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                final_ret = max(final_ret, dfs(memo, matrix, i, j));
            }
        }
        return final_ret;
    }
};
// @lc code=end

