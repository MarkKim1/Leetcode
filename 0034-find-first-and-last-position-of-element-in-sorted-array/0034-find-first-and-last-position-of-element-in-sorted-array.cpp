class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                if(mid - 1 >= 0 and nums[mid - 1] == nums[mid]){
                    right = mid - 1;
                    continue;
                }
                result.push_back(mid);
                break;
            }
            if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        left = 0;
        right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                if(mid + 1 < nums.size() and nums[mid + 1] == nums[mid]){
                    left = mid + 1;
                    continue;
                }
                result.push_back(mid);
                return result;
            }
            if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return {-1,-1};
    }
};