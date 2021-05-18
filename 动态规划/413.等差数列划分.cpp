/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    int contPossbility(int n) {
        int summ = 0;
        for (int i = 3; i <= n; i++) {
            summ += (n - i + 1);
        }
        return summ;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return 0;
        }
        int ret = 0;
        int differ = nums[1] - nums[0];
        int curCont = 2;    // 2表示至少一前一后两个数字
        for (int i = 2; i < len; i++) {
            if (nums[i] - nums[i - 1] == differ) {
                curCont++;
            } else {
                if (curCont >= 3) {
                    ret += contPossbility(curCont);
                }
                differ = nums[i] - nums[i - 1];
                curCont = 2;
            }
        }
        if (curCont >= 3) {
            ret += contPossbility(curCont);
        }
        return ret;
    }
};
// @lc code=end

