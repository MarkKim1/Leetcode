class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            int tempMax = max(curr,max(maxSoFar * curr,minSoFar * curr));
            minSoFar = min(curr,min(minSoFar * curr,maxSoFar*curr));
            maxSoFar = tempMax;
            result = max(maxSoFar,result);
        }
        return result;
    }
};