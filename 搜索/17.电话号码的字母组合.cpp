/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    map<char, string> mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},
                        {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
                        {'8',"tuv"},{'9',"wxyz"}};    
    vector<string> res;
    string cur;

    void dfs(int idx, string digits) {
        if( idx == digits.size() ) {
            res.push_back(cur);
            return;
        }
        for(int i=0; i<mp[digits[idx]].size(); i++) {
            cur.push_back( mp[digits[idx]][i] );
            dfs(idx+1,digits);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        dfs(0,digits);
        return res;
    }
};
// @lc code=end

