class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] = max(nums[i], nums[i- 1] + nums[i]);
            currMax = max(currMax,nums[i]);
        }
        return currMax;
    }
};