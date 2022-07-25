class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int currsum = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            currsum = max(currsum + nums[i],nums[i]);
            result = max(result,currsum);
        }
        return result;
    }
};