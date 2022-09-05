class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2 != 0) return false;
        sum/=2;
        set<int> dp;
        dp.insert(0);
        for(int i = nums.size()-2; i >=0; i--){
            set<int> temp = dp;
            for(auto a : temp){
                if(a + nums[i] == sum) return true;
                dp.insert(a + nums[i]);
            }
        }
        return false;
    }
};