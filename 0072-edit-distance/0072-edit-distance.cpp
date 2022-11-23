class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size();
        int col = word2.size();
        if(row * col == 0){
            return row + col;
        }
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        for(int i = 0; i < row+1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i < col+1; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i < dp.size(); i++){// word1
            for(int j = 1; j < dp[0].size(); j++){ // word2
                int up = dp[i-1][j] + 1;
                int left = dp[i][j-1] + 1;
                int left_up = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]){
                    left_up++;
                }
                dp[i][j] = min(up,min(left,left_up));
            }
        }
        return dp[row][col];
    }
};