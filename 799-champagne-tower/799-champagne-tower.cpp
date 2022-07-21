class Solution {
public:
    double champagneTower(int poured, int row, int col) {
        double dp[102][102] = {0.0};
        dp[0][0] = (double)poured;
        for(int i = 0; i <= row; i++){
            for(int j = 0; j <= col; j++){
                double toPour = (dp[i][j] - 1.0) / 2.0;
                if(toPour > 0){
                    dp[i+1][j] += toPour;
                    dp[i+1][j+1] += toPour;
                }
            }
        }
        double answer = min(1.0, dp[row][col]);
        return answer;
    }
};