class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> dp;
        dp.insert(0);
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum+=nums[i];
        }
        if(totalSum % 2 != 0)return false;
        int target = totalSum/2;
        for(int i = nums.size()-1; i >= 0; i--){
            unordered_set<int> nextdp;
            nextdp.insert(nums[i]);
            for(auto t: dp){
                if(t+nums[i] == target) return true;
                nextdp.insert(t+nums[i]);
                nextdp.insert(t);
            }
            dp = nextdp;
        }
        return false;
    }
};