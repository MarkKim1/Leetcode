class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        vector<int> maximum(nums.size());
        vector<int> minimum(nums.size());
        vector<int> result;
        maximum[0] = nums[0];
        minimum[nums.size()-1] = nums[nums.size()-1];
        for(int i = 1; i < nums.size(); i++){
            if(i % k == 0){
                maximum[i] = nums[i];
                continue;
            }
            maximum[i] = max(maximum[i-1],nums[i]);
            
        }
        for(int i = nums.size()-2; i >= 0; i--){
            if((i-k+1) % k == 0){
                minimum[i] = nums[i];
                continue;
            }
            minimum[i] = max(minimum[i+1],nums[i]);
        }
        for(int i = k-1; i < nums.size(); i++){
            result.push_back(max(minimum[i-k+1],maximum[i]));
        }
        return result;
    }
};