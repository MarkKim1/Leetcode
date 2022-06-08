class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int memo[1001][1001] = {0};
        for(int row = text1.size()-1;row>= 0; row--){
            for(int col = text2.size()-1; col>=0; col--){
                if(text1[row] == text2[col]){
                    memo[row][col] = 1 + memo[row+1][col+1];
                }else{
                    memo[row][col] = max(memo[row][col+1],memo[row+1][col]);
                }
            }
        }
        return memo[0][0];
    }
};