class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        int ROW = grid.size();
        int COL = grid[0].size();
        for(int i = 1; i <COL; i++){
            grid[0][i] +=grid[0][i-1];
        }
        for(int i = 1; i < ROW; i++){
            grid[i][0] +=grid[i-1][0];
        }
        for(int i = 1; i < ROW; i++){
            for(int j = 1; j < COL; j++){
                grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[ROW-1][COL-1];
    }
};
// [[1,2,3],[4,5,6],[4,5,6],[4,5,6],[4,5,6]]