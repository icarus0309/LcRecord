/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start

class Solution {
private:
    vector<vector<int>> retAllPermute;
    vector<int> feasibleSolution;
public:
    void backTrace(vector<int>& nums, vector<bool>& passed)
    {
        int numSize = nums.size();
        if (this->feasibleSolution.size() == numSize) {
            this->retAllPermute.push_back(
                vector<int>(this->feasibleSolution.begin(), 
                            this->feasibleSolution.end())
            );
            return;
        }
        unordered_set<int> antiDuplicateCurLayer;
        for (int i = 0; i < numSize; i++) {
            if ((!passed[i]) && 
                (antiDuplicateCurLayer.find(nums[i]) == antiDuplicateCurLayer.end())
                ) {
                antiDuplicateCurLayer.insert(nums[i]);
                passed[i] = true;
                this->feasibleSolution.push_back(nums[i]);
                backTrace(nums, passed);
                passed[i] = false;
                this->feasibleSolution.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<bool> passed(nums.size(), false);
        this->feasibleSolution.clear();
        backTrace(nums, passed);
        return this->retAllPermute;
    }
};
// @lc code=end

