class Solution {
public:
    int n;
    int m;
    int memo[1001][1001] = {};
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        this->n = nums.size();
        this->m = multipliers.size();
        return dp(0,0,nums,multipliers);
    }
    
    int dp(int i, int left,vector<int>& num, vector<int>& multi){
        if(i == m) return 0;
        int mult = multi[i];
        int right = n - 1 - (i - left);
        if(memo[i][left] == 0){
        memo[i][left] = max(mult * num[left] + dp(i+1,left+1,num,multi),
                            mult * num[right] + dp(i+1,left,num,multi));
        }
        return memo[i][left];
    }
};