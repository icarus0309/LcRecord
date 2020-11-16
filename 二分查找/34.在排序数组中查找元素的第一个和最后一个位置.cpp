/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int res1 = firstRange(nums,target);
        int res2 = firstRange(nums,target+1)-1;
        if(res1 == nums.size() || nums[res1]!=target) {//后面的条件是为了防止不连续
            return vector<int> {-1,-1};
        }else
            return vector<int> {res1,res2};
    }

    int firstRange(vector<int>& nums, int target){
        int l = 0, r = nums.size();//这个初始值绝了哈哈哈
        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

