/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.begin(),nums.end()).size();
        //果然初始化set的参数只需要首地址和末地址就可以了
    }
};
// @lc code=end

/*
    bool containsDuplicate(vector<int>& nums) {

         return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size(); 
         //如果原数组的大小>集合的大小，则说明存在重复元素
    }
*/
