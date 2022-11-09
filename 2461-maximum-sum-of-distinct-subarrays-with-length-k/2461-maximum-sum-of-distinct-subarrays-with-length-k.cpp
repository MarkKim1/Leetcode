class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long sum = 0;
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            sum+=nums[i];
            if(i >= k-1){
                if(map.size() == k){
                    ans = max(ans,sum);
                }
                sum-=nums[i-k+1];
                if(--map[nums[i-k+1]] == 0){
                    map.erase(nums[i-k+1]);
                }
            }
        }
        return ans;
    }
};