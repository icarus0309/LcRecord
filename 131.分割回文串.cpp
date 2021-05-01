/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ret;
    vector<string> iter_ret;
    string iter_str;

    void backTrace(string& s, int pos) const
    {
        
    }

    vector<vector<string>> partition(string s)
    {
        ret.clear();
        iter_ret.clear();
        iter_str = "";
        backTrace(s, 0);
        return ret;
    }
};
// @lc code=end

