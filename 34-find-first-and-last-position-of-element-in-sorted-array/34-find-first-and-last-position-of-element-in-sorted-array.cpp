class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || (nums.size() == 1 && nums[0] != target)){
            return {-1,-1};
        }
        int left = 0;
        int right = nums.size()-1;
        int leftTarget = nums[0];
        int rightTarget = nums[nums.size()-1];
        vector<int> ans;
        while(leftTarget != target || rightTarget != target){
            if(leftTarget != target){
                left++;
                leftTarget = nums[left];
            }
            if(rightTarget != target){
                right--;
                rightTarget = nums[right];
            }
            if(left > right){
                return {-1,-1};
            }
        }
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};