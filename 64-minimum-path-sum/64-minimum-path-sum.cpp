class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 1 and grid[0].size() == 1) return grid[0][0];
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col];
        dp[row-1][col-1] = grid[row-1][col-1];
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j>=0; j--){
                if(i == row-1 and j>=1){
                    dp[i][j-1] = grid[i][j-1] + dp[i][j];
                }else if(j == col-1 and i >= 0){
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                }else if(j != col-1 and i != row-1){
                    dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};