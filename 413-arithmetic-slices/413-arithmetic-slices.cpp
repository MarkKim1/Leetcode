class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0; 
        int result = 0;
        vector<int> dp(nums.size(),0);
        for(int i = 2; i < nums.size(); i++){
            if(nums[i]-nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1] + 1;
                result+=dp[i];
            }
        }
        return result;
    }
};