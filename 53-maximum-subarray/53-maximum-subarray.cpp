class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i],nums[i] + dp[i-1]);
            result = max(result,dp[i]);
        }
        return result;
    }
};