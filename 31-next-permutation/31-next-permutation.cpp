class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i >=0 and nums[i] >= nums[i+1]){
            i--;
        }
        int j = nums.size()-1;
        if(i >= 0){
            while(nums[j] <= nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin() + i+1,nums.end());
    }
};