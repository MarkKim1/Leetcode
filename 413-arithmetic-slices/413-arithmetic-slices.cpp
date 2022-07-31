class Solution {
public:
    int sum = 0;
    int numberOfArithmeticSlices(vector<int>& nums) {
        slices(nums,nums.size()-1);
        return sum;
    }
    int slices(vector<int>& nums, int i){
        if(i < 2){
            return 0;
        }
        int ap = 0;
        if(nums[i]-nums[i-1] == nums[i-1] - nums[i-2]){
            ap = 1 + slices(nums,i-1);
            sum +=ap;
        }else{
            slices(nums,i-1);
        }
        return ap;
    }
};