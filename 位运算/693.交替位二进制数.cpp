/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n&1;
        n = n>>1;
        while(n) {
            if(last==(n&1))
                return false;
            last = n&1;
            n = n>>1;
        }
        return true;
    }
};
// @lc code=end

