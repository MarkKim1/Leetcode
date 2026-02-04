class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0;
        for(; i < nums.size()-1; i++){
            if(nums[i] >= nums[i + 1]){
                break;
            }
        }
        if(i == nums.size() - 1 || i == 0) return false;
        for(; i < nums.size() - 1; i++){
            if(nums[i] <= nums[i + 1]){
                break;
            }
        }
        if(i == nums.size() - 1) return false;
        for(; i < nums.size() - 1; i++){
            if(nums[i] >= nums[i + 1]){
                return false;
            }
        }
        return true;
    }
};