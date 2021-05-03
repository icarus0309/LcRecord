/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> f;
    vector<vector<string>> ret;
    vector<string> iter_ret;

    void backTrace(string s, int pos)
    {
        if (pos == s.size()) {
            ret.push_back(iter_ret);
            return;
        }
        for (int i = pos; i < s.size(); i++) {
            if (!f[pos][i])// 不符合回文条件
                continue;
            else {
                iter_ret.push_back(s.substr(pos, i - pos + 1));
                backTrace(s, i + 1);
                iter_ret.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        ret.clear();
        iter_ret.clear();
        int n = s.size();
        f.assign(n, vector<bool>(n, true));
        for (int j = 1; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                f[i][j] = f[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        backTrace(s, 0);
        return ret;
    }
};
// @lc code=end

