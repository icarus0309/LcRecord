/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> iter_ret;

    void backTrace(int n, int k, vector<bool>& passed, int start)
    {
        if (iter_ret.size() == k) {
            ret.push_back(vector<int>(iter_ret.begin(), iter_ret.end()));
            return;
        }
        for (int i = start; i < n; i++) {
            if (passed[i] == true)
                continue;
            passed[i] = true;
            iter_ret.push_back(i + 1);
            backTrace(n, k, passed, i + 1);
            passed[i] = false;
            iter_ret.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        ret.clear();
        iter_ret.clear();
        vector<bool> passed(n, false);
        backTrace(n, k, passed, 0);
        return ret;
    }
};
// @lc code=end

