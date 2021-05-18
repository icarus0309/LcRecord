/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>> dp;
        sort(pairs.begin(), pairs.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        for (auto& p : pairs) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = (left + right) >> 1;
                if (p[0] > dp[mid][1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left >= dp.size()) {
                dp.push_back(p);
            } else if (p[1] < dp[left][1]) {
                dp[left] = p;
            }
        }
        return dp.size();
    }
};
// @lc code=end

