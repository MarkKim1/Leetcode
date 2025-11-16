class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        int root = right;
        left = 0;
        right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            int realmid = (mid + root) % nums.size();
            if(nums[realmid] == target) return realmid;
            if(nums[realmid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};