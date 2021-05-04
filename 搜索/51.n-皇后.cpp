/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<bool> row;
    vector<bool> col;
    vector<bool> oblique_lines;
    vector<bool> oblique_lines_v2;
    vector<string> iter_ret;
    vector<vector<string>> ret;

    void backTrace(int n, int i)
    {
        if (iter_ret.size() == n) {
            ret.push_back(iter_ret);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!row[i] && !col[j] && !oblique_lines[i + j] && !oblique_lines_v2[i + n - j]) {
                row[i] = col[j] = oblique_lines[i + j] = oblique_lines_v2[i + n - j] = true;
                string temp_str = string(n, '.');
                temp_str[j] = 'Q';
                iter_ret.push_back(temp_str);
                backTrace(n, i+1);
                iter_ret.pop_back();
                row[i] = col[j] = oblique_lines[i + j] = oblique_lines_v2[i + n - j] = false;   
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        row = vector<bool>(n, false);
        col = vector<bool>(n, false);
        oblique_lines = vector<bool>(2 * n - 1, false);
        oblique_lines_v2 = vector<bool>(2 * n - 1, false);
        backTrace(n, 0);
        return ret;
    }
};
// @lc code=end

