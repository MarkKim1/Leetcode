class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int end = nums.size()-1;
        reverse(nums,0,end);
        reverse(nums,0,k-1);
        reverse(nums,k,end);
    }
    void reverse(vector<int>&nums, int start, int end){
        while(start < end){
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
    
};