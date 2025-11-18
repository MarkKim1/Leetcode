class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        k = nums.size() - k;
        while(true){
            int index = partition(nums, left, right,k);
            if(index == k) return nums[index];
            if(index < k){
                left = index + 1;
            }
            else right = index - 1;
        }
        return 1;
    }
    int partition(vector<int>& nums, int left, int right, int k){
        int pivot = nums[left];
        int l = left;
        left += 1;
        while(left <= right){
            if(nums[left] > pivot and nums[right] < pivot){
                swap(nums[left++], nums[right--]);
            }
            if(nums[left] <= pivot){
                left++;
            }
            if(nums[right] >= pivot){
                right--;
            }
        }
        swap(nums[right], nums[l]);
        return right;
    }
};