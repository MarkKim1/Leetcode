class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        int currMax = 0;
        int currMin = 0;
        for(auto a : nums){
            total += a;
            currMax = max(currMax + a, a);
            currMin = min(currMin + a, a);
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        return maxSum > 0 ? max(maxSum,total - minSum) : maxSum;
    }
};