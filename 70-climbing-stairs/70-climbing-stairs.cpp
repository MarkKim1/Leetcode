class Solution {
public:
    unordered_map<int,int> memo;
    
    int climbStairs(int n) {
        // int f[46] = {0};
        // f[0] = 0;
        // f[1] = 1;
        // f[2] = 2;
        // for(int i = 3; i <= n; i++){
        //     f[i] = f[i-1] + f[i-2];
        // }
        // return f[n];
        if(memo.find(n) != memo.end()) return memo[n];
        if(n == 0)return 1;
        if(n < 0) return 0;
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};