/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int str2num(string word) {
        int res=0;
        for(char c:word) {
            res |= 1<< (c-'a');
        }
        return res;
    }

    int maxProduct(vector<string>& words) {
        vector<int> m(words.size(),0);
        for(int i=0; i<words.size(); i++) {
            m[i] = str2num(words[i]);
        }
        int res = 0;        
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<i; j++) {
                if((m[i]&m[j])==0 && words[i].size()*words[j].size()>res) {
                    res = words[i].size()*words[j].size();
                }
            }
        }
        return res;
    }

};
// @lc code=end

