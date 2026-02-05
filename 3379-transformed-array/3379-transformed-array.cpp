class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            //((0 + 3)%(4 + 4)) % 4
            result[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return result;
    }
    
};