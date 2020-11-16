/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
private:
    int* sums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums = new int[n+1];
        sums[0] = 0;
        for(int i=1; i<n+1; i++) {
            sums[i] = sums[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return this->sums[j] - this->sums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

