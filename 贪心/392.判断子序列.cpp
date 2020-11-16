/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ps=0, pt=0;
        for(;pt<t.length();pt++){
            if(s[ps]==t[pt]){
                ps++;
            }
        }
        if(ps == s.length()) return true;
        return false;
    }
};
// @lc code=end

