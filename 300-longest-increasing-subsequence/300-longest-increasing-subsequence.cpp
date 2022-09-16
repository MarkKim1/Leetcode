class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(result.empty() or result.back() < nums[i]){
            result.push_back(nums[i]);
            }else{
                auto it = lower_bound(result.begin(),result.end(),nums[i]);
                *it = nums[i];
            }
        }
        return result.size();
    }
};