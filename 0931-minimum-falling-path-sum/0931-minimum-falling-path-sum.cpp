class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        int ans = INT_MAX;
        for(int row = matrix.size()-1; row >= 0; row--){
            for(int col = matrix[0].size()-1; col >= 0; col--){
                if(row == matrix.size()-1){
                    dp[row][col] = matrix[row][col];
                }else if(col == matrix[0].size()-1){
                    dp[row][col] = min(dp[row+1][col],dp[row + 1][col-1]) + matrix[row][col];
                }else if(col == 0){
                    dp[row][col] = min(dp[row + 1][col],dp[row + 1][col + 1]) + matrix[row][col];
                }else{
                    dp[row][col] = min(dp[row + 1][col],min(dp[row + 1][col+1],dp[row + 1][col-1])) + matrix[row][col];
                }
                if(row == 0){
                        ans = min(ans,dp[row][col]);
                    }
            }
        }
        return ans;
    }
};