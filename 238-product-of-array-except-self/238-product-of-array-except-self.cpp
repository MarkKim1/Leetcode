class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        int n = nums.size()-1;
        for(int i = 1; i < nums.size(); i++){
            left[i] = nums[i-1] * left[i-1];
            right[n-i] = nums[n-i+1] * right[n-i+1];
        }
        for(int i = 0; i < left.size(); i++){
            left[i] = left[i] * right[i];
        }
        return left;
    }
};