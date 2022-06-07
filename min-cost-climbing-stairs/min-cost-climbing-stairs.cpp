class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        unordered_map<int,int> memo;
        return dp(cost,n,memo);
    }
    
    int dp(vector<int>& cost, int n, unordered_map<int,int>& memo){
        memo[0] = cost[0];
        memo[1] = cost[1];
        for(int i = 2; i < n; i++){
            if(memo.find(i) == memo.end()){
                memo[i] = cost[i] + min(memo[i-1],memo[i-2]);
            }
        }
        return memo[n-1] > memo[n-2] ? memo[n-2] : memo[n-1];
    }
};