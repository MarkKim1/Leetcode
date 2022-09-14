class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            int temp = max(nums[i],max(maxSoFar * nums[i],minSoFar * nums[i]));
            minSoFar = min(nums[i],min(maxSoFar * nums[i],minSoFar * nums[i]));
            maxSoFar = temp;
            result = max(maxSoFar,result);
        }
        return result;
    }
};