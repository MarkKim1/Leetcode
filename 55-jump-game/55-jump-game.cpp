class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i = 0; i <= reach; i++){
            reach = max(nums[i]+i,reach);
            if(reach >= nums.size()-1) {
                return true;
            }
        }
        return false;
    }
};