class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i],dp[i-1] + nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};