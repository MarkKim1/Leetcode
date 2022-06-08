class Solution {
public:
    int n;
    int m;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        this->n = nums.size();
        this->m = multipliers.size();
        int memo[1001][1001] = {};
        
        for(int i = m-1; i >= 0; i--){
            for(int left = i; left >= 0; left--){
                int right = n - 1 - (i - left);
                memo[i][left] = max(multipliers[i] * nums[left] + memo[i+1][left+1],
                                    multipliers[i] * nums[right] + memo[i+1][left]);
            }
        }
        
        return memo[0][0];
    }
};