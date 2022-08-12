class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        int first = helper(nums,0,nums.size()-1);
        int second = helper(nums,1,nums.size());
        int total = max(first,second);
        return total;
    }
    int helper(vector<int>& nums,int start, int end){
        vector<int> dp(end-start,0);
        dp[0] = nums[start];
        dp[1] = max(dp[0],nums[start+1]);
        for(int n = 2; n < dp.size(); n++){
            dp[n] = max(dp[n-1],dp[n-2] + nums[n+start]);
        }
        return dp.back();
    }
};