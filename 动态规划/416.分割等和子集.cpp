/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start

//懂了已经，但是暂时不求掌握
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int it:nums) sum += it;
        //剪枝：和为奇数
        if (sum % 2 == 1) return false;
        //加速运算：逆序排序
        sort(nums.begin(),nums.end(),[](const int& a,const int& b){return a>b;});
        //剪枝：出现大于sum/2的元素
        if (nums[0]>sum/2) return false;
        //从第一个开始找
        return find(nums, 0, sum/2);
    }

    bool find(vector<int>& nums, int start, int remain){
        //边界1:找到了
        if (remain == 0) return true;   
        //边界2：index超过范围
        if (start >= nums.size()) return false;     //这是终止条件
        //情况1:当前数等于目标数
        if (nums[start] == remain) return true;   //这一步必需存在，否则有的情况到了最后一步就无法实现了
        //呃好吧，其实也可以不存在，但那必需在底下改成小于等于，但这样速度会慢一些，因为要多进行一步判断。
        //情况2:当前数小于目标数
        else if (nums[start] < remain)
            //分为2种情况，当前数我既可以选它，也可以不选它，递归
            return find(nums, start+1, remain-nums[start]) || find(nums, start+1, remain);
        //情况3:当前数大于目标数，肯定不选。
        return find(nums, start+1, remain);
    }
};



// @lc code=end


/*
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        //这一题的核心思想是：能够到达一半值，只要有能够到达一半值的组合存在，那么互斥集合也一定可以
        int summ = 0;
        for(int i:nums) {
            summ += i;
        }
        if(summ%2) return false;
        int target = summ/2;
        vector<bool> dp(target+1);
        dp[0] = true;
        for(int num:nums) {
            for(int i=target; i>=num; i--) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[target];
    }
};
*/




