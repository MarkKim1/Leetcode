class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            result[(i+k) % nums.size()] = nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = result[i];
        }
    }
};