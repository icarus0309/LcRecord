/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(mid%2==0){
                mid++;
            }
            if(nums[mid]!=nums[mid+1]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return nums[l];
    }
};

// @lc code=end

