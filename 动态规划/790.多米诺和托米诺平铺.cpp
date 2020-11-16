/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */

// @lc code=start

//vector必需先push_back才能操作
class Solution {
public:
    int numTilings(int N) {
        long mod = 1e9+7;
        long* dp = new long[N+3];
        dp[0] = 1; 
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4; i<=N; i++) {
            dp[i] = (2*dp[i-1]%mod + dp[i-3]%mod)%mod;
        }
        return dp[N];   
    }
};

// @lc code=end

/*
class Solution {
    private int mod = 1000000007;
    public int numTilings(int N) {
        int[] dp = new int[N+3];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i <= N; i++){
            dp[i] = (2*(dp[i-1] % mod) % mod + dp[i-3] % mod) % mod;
        }
        return dp[N];
    }
}
*/