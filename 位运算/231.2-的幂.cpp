/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        int cnt=0;
        while(n) {
            if(n&1) 
                cnt++;
            if(cnt==2) break;
            n = n>>1;
        }
        return cnt<2?true:false;
    }
};

// @lc code=end

