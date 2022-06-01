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
            swap(nums,i,j);
        }
        reverse(nums,i+1);
    }
    void swap(vector<int>&nums, int i, int j){
        int temp;
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverse(vector<int>&nums,int i){
        int j = nums.size()-1;
        while(i < j){
            swap(nums,i,j);
            j--;
            i++;
        }
    }
};