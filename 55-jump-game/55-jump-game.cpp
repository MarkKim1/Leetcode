class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i = 0; i <= reach; i++){
            int jump = max(i + nums[i],reach);
            if(jump >= nums.size()-1){
                return true;
            }
            reach = jump;
        }
        return false;
    }
};