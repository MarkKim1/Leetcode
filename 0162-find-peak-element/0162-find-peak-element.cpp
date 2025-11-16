class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n = nums.size() - 1;
        if(nums[0] > nums[1]) return 0;
        if(nums[n] > nums[n - 1]) return n;

        int left = 1;
        int right = nums.size() - 2;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid - 1] < nums[mid] and nums[mid] > nums[mid + 1]) return mid;
            else if(nums[mid] < nums[mid - 1]) right = mid - 1;
            else if(nums[mid] < nums[mid + 1]) left = mid + 1;
        }
        return -1;
    }
};