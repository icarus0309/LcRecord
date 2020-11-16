/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        int t = num&(-num);
        if(num-t!=0) return false;
        return num%3==1; 
        //直接对4进行求余数的话，0和1是通不过的，因为0不是，1是。
    }
};
// @lc code=end

