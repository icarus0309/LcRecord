/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> iter_ret;

    void backTrace(vector<int>& candidates, int target, int pos, int summ)
    {
        if (summ == target) {
            ret.push_back(vector<int>(iter_ret));
            return;
        }
        else if (summ > target) {
            return;
        }
        int i = pos;
        // 解集定长用for+passed组合，不定长还是用while+pos组合吧
        while (i < candidates.size()) {
            summ += candidates[i];
            iter_ret.push_back(candidates[i]);
            backTrace(candidates, target, i+1, summ);
            summ -= candidates[i];
            iter_ret.pop_back();
            // i++;
            while (++i < candidates.size() && candidates[i-1] == candidates[i]) {}
            // 虽然有的编译器可能会报错但既然能通过那我就不客气了
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        ret.clear();
        iter_ret.clear();
        sort(candidates.begin(), candidates.end());
        backTrace(candidates, target, 0, 0);
        return ret;
    }
};
// @lc code=end

