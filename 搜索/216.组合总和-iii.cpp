/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> iter_ret;

    void backTrace(int k, int n, int pos, int summ)
    {
        if (iter_ret.size() == k) {
            if (summ == n)
                ret.push_back(vector<int>(iter_ret));
            return;
        }
        int i = pos;
        while (i < 10) {
            summ += i;
            iter_ret.push_back(i);
            backTrace(k, n, i+1, summ);
            iter_ret.pop_back();
            summ -= i;
            i++;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        ret.clear();
        iter_ret.clear();
        backTrace(k, n, 1, 0);
        return ret;
    }
};
// @lc code=end

