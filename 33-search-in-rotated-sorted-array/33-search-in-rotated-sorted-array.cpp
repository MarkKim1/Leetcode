class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return NULL;
        }
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            if(nums[left] != target){
                left++;
            }
            if(nums[right] != target){
                right--;
            }
        }
        if(nums[left] == target){
            return left;
        }
        else if(nums[right] == target){
            return right;
        }
        return -1;
    }
};