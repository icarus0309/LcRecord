/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        if(target < letters[0] || letters[len-1]<=target) 
            return letters[0];
        int l=0, r=len-1, mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(letters[mid]<=target){
                l = mid+1;
            }else{
                r = mid-1;                
            }
        }
        return letters[l];
    }
};

// @lc code=end

