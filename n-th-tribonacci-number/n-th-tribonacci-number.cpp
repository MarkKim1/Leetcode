class Solution {
public:
    
    int tribonacci(int n) {
        unordered_map<int,int> memo;
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        return dp(n, memo);
        
    }
    
    int dp(int n, unordered_map<int,int>& memo){
        if(memo.find(n) != memo.end()) return memo[n];
        if(n == 0) return 0;
        memo[n] = dp(n-1,memo) + dp(n-2,memo) + dp(n-3,memo);
        return memo[n];
    }
};