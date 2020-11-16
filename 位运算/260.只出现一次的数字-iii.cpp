/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        vector<int> res(2,0);
        for(int num:nums) {
            s ^= num;
        }
        int  k = s&(-s);    
        //k不一定唯一，只需要是一个单1的数，而且这个1的位置必需是s上为1的就可以1了
        //不过s&(-s)这个运算确实巧妙，能得到s的最后为1的那一位，其余则全部为0
        for(int num:nums) {
            if(k&num) {
                res[0] ^= num;
            } else
                res[1] ^= num;
        }
        return res;
    }
};
// @lc code=end

