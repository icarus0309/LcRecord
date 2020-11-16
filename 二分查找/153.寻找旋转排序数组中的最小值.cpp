/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>nums[r])
                l = mid+1;
            else r = mid;
        }
        return nums[l];
    }
};
// @lc code=end

