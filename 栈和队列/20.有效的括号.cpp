/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char,char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        for(char i:s) {
            switch (i) {
                case ')': case '}': case ']':
                    if(!stk.empty() && stk.top()==mp[i])
                        stk.pop();
                    else stk.push(i);
                    break;
                default:
                    stk.push(i);
                    break;
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};
// @lc code=end

