/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:

    int numDecodings(string s)
    {
        int len = s.size();
        vector<int> ret = vector<int>(len + 1, 0);
        ret[0] = 1;
        for (int i = 1; i <= len; i++) {
            if (s[i - 1] != '0') {
                ret[i] += ret[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)) {
                ret[i] += ret[i - 2];
            }
        }
        return ret[len];
    }
};
// @lc code=end

