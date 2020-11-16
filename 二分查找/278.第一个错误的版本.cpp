/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, r=n;
        while(1){
            int mid = l+(r-l)/2;
            if(isBadVersion(mid)){
                if(!isBadVersion(mid-1))
                    return mid;
                r = mid-1;
            }
            else{
                if(isBadVersion(mid+1))
                    return mid+1;
                l = mid+1;
            }
        }
    }
};
// @lc code=end

