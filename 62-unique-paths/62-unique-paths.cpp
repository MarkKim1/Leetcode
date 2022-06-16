class Solution {
public:
    int dp[101][101]{};
    int uniquePaths(int m, int n) {
        int row = 0;
        int col = 0;
        return dfs(row,col,m,n);
    }
    int dfs(int row, int col, int m, int n){
        if(row >= m || col >= n) return 0;
        if(row == m-1 && col == n-1){
            return 1;
        }
        if(dp[row][col]>0) return dp[row][col];
        
        return dp[row][col] = dfs(row+1,col,m,n) + dfs(row,col+1,m,n);
    }
};