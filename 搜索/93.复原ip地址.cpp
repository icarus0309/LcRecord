/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
private:
    vector<string> ipAddrs;
    vector<int> curStrs;
    static constexpr int SEG_COUNT = 4;
public:
    //1.当前已有几个字段 2.当前的位置 3.原始字符串
    void dfs(int curIdx, int startLoc, string s) {
        // 但凡是进了这个函数了，说明已经在重新找单词了。
        if(curIdx == SEG_COUNT) {
            if(startLoc == s.size()) {
                string ans;
                for(int i=0; i<SEG_COUNT; i++) {
                    ans += to_string(curStrs[i]);
                    if(i != SEG_COUNT - 1) ans += '.';
                }
                ipAddrs.push_back(move(ans));
            }
            return;
        }

        if(startLoc == s.size()) return;

        if(s[startLoc] == '0') {
            curStrs[startLoc] = 0;
            dfs(curIdx+1, startLoc+1, s);
        }

        int curNum = 0;
        for(int endLoc = startLoc; endLoc < s.size(); endLoc++) {
            curNum = curNum*10 + (s[endLoc] - '0');
            if(curNum > 0 && curNum <= 0xFF) {
                curStrs[curIdx] = curNum;
                dfs(curIdx+1, endLoc+1, s);
            } else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        curStrs.resize(SEG_COUNT);
        dfs(0,0,s);
        return ipAddrs;
    }

};

// @lc code=end

