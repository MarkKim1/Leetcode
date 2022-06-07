class Solution {
public:
    int f[101];
    int rob(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> memo;
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return dp(nums,n,memo);
    }
    
    int dp(vector<int>& nums, int n,unordered_map<int,int>& memo){
        memo[0] = nums[0];
        memo[1] = max(nums[0],nums[1]);
        for(int i = 2; i <n; i++){
            if(memo.find(i) == memo.end())
                memo[i] = max(memo[i-1],memo[i-2] + nums[i]);
        }
        return memo[n-1];
    }
};