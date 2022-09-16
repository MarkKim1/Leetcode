class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j] +1);
                }
            }
        }
        int result = INT_MIN;
        for(int a : dp){
            result = max(a,result);
        }
        return result;
    }
};