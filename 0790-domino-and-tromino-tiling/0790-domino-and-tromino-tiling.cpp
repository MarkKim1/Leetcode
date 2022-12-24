class Solution {
public:
    int numTilings(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        int MOD = 1000000007;
        for(int i = 3; i <= n; i++){
            dp[i] = (2 * dp[i-1] + dp[i-3]) % MOD;
        }
        return (int)dp[n];
    }
};