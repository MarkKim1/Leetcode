class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        int result = 0;
        for(int i = 2; i < cost.size(); i++){
            dp[i] = min(dp[i-2],dp[i-1]) + cost[i];
        }
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};