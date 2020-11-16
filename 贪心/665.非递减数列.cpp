/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        /*
        if(nums.size()<=2) return true;
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt < 2; i++) {
            if (nums[i] >= nums[i - 1]) {
                continue;
            }
            cnt++;
            if (i - 2 >= 0 && nums[i - 2] > nums[i]) {
                nums[i] = nums[i - 1];
            }
        }
        return cnt <= 1;
        */
        
        if(nums.size()<=2) return true;
        int i = 0, num = 0, tmp = 0;
        int tmp_before;
        for(; i<nums.size()-1 && num<2; i++){ //加上第二个条件，可以省去很多判断
            if(nums[i]>nums[i+1]){
                tmp = nums[i+1] - nums[i];
                tmp_before = i>0? nums[i-1] : -1e5;
                num++;
            }else if(tmp<0){
                if(nums[i] < tmp_before && nums[i+1] < nums[i-1])
                    return false;
                tmp = 0;
            }
        }
        return num<=1;
        
    }
};

// @lc code=end

