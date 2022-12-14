class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if(nums.size() == 1) return dp[0];
        dp[1] = nums[1];
        if(nums.size() == 2){
            return max(dp[1],dp[0]);
        }
        dp[2] = dp[0] + nums[2];
        for(int i = 3; i < nums.size(); i++){
            dp[i] = max(dp[i-2],dp[i-3]) + nums[i];
        }
        return max(dp[nums.size()-1],dp[nums.size()-2]);
    }
};