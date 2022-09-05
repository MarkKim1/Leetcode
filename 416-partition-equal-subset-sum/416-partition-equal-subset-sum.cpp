class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2 != 0) return false;
        sum /=2;
        vector<vector<int>> memo(nums.size(),vector<int>(sum+1,-1));
        if(helper(0,sum,nums,memo)){
            return true;
        }
        return false;
    }
    bool helper(int start, int sum, vector<int>& nums, vector<vector<int>>& memo){
        if(sum == 0) return true;
        if(sum < 0 || start == nums.size()) return false;
        if(memo[start][sum] != -1) return memo[start][sum];
        bool result = helper(start+1,sum-nums[start],nums,memo) || helper(start+1,sum,nums,memo);
        memo[start][sum] = result;
        return result;
    }
};