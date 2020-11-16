/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int l=0, r=x, mid, res=0;
        while(l <= r){
            mid = l+(r-l)/2;
            if((long long)mid*mid <= x){
                res = mid;
                l = mid+1;
            }
            else r = mid-1;
        } 
        return res;
    }
};

// @lc code=end

