/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> iter_ret;

    void backTrace(vector<int>& candi, int target, int pos, int* p_summ)
    {
        if (*p_summ  == target) {
            ret.push_back(vector<int>(iter_ret));
            return;
        } else if (*p_summ  > target) {
            return;
        }
        int i = pos;
        while (i < candi.size()) {
            iter_ret.push_back(candi[i]);
            *p_summ += candi[i];
            backTrace(candi, target, i, p_summ);
            *p_summ -= candi[i];
            iter_ret.pop_back();
            i++;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        ret.clear();
        iter_ret.clear();
        int summ = 0;
        backTrace(candidates, target, 0, &summ);
        return ret;
    }
};
// @lc code=end

