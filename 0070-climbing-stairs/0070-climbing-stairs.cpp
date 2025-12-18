class Solution {
public:
    int result = 0;
        
    int climbStairs(int n) {
        vector<int> dp(46,INT_MAX);
        return helper(n,dp);
        
    }
    int helper(int n,vector<int>& dp){
        if(n < 0) return 0;
        if(dp[n] != INT_MAX) return dp[n];
        if(n == 0) return 1;
        
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
};