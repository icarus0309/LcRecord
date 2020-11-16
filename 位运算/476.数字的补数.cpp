/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int tmp=num,cnt=0;
        while(tmp) {cnt++;tmp>>=1;}
        return num^((long)(1<<cnt)-1);
    }
};
// @lc code=end

