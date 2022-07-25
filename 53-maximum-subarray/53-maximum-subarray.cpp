class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int currsum = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > currsum){
                currsum = max(nums[i]+currsum,nums[i]);
            }else{
                currsum+=nums[i];
            }
            result = max(currsum,result);
        }
        return result;
    }
};