class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        int ROW = matrix.size();
        int COL = matrix[0].size();
        int area = 0;
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                    area = max(area,dp[i][j]);
                }else if(matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                    area = max(area,dp[i][j]);
                }
            }
        }
        return area * area;
    }
};