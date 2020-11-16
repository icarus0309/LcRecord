/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start

class Solution {
public:
    //转化思路很巧妙：通过与总和相加，得出一个数，数字和为这个数的可能性数量就是答案
    //换言之，消去了负号的影响
    int findTargetSumWays(vector<int>& nums, int S) {
        int summ = 0;
        for(int i: nums) summ+=i;
        if(summ<S || (S+summ)%2) return 0;
        return tarSets(nums,(S+summ)/2); 
    }
    //求满足的子集数量
    int tarSets(vector<int>& nums, int tar) {
        vector<int> dp(tar+1);
        dp[0] = 1;  //dp[0]为1的原因是每个数字实现自身的途径至少为1
        for(int i:nums) {
            for(int j=tar; j>=i; j--) {
                dp[j] += dp[j-i];   //即在原有的基础上加上实现j-i处的途径数量
                //不用担心重复，在脑子里过一遍就可以了，毕竟是从1开始加
            }
        }
        return dp[tar];
    }
};

// @lc code=end

