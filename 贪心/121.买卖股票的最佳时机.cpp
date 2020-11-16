/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int res = 0;        
        int min_price = prices[0];
        for(int i=1; i<prices.size(); i++){
        /*
        for(int& a : prices){
        
            res = max(res,a-min_price);
            min_price = min_price<a?min_price:a;
            */
            if(min_price>prices[i]) 
                min_price = prices[i];
            else//看来用else if会降低速度
                res  = max(res,prices[i]-min_price);                
        }
        return res;
    }
};
// @lc code=end

