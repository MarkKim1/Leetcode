class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        if(grid[0][0] == 1){
            return 0;
        }
        grid[0][0] = 1;
        
        for(int i = 1; i < COL; i++){
            grid[0][i] = grid[0][i] == 0 and grid[0][i-1] == 1 ? 1 : 0;
        }
        for(int i = 1; i < ROW; i++){
            grid[i][0] = grid[i][0] == 0 and grid[i-1][0] == 1 ? 1 : 0;
        }
        for(int i = 1; i < ROW; i++){
            for(int j = 1; j < COL; j++){
                if(grid[i][j] == 0){
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }else{
                    grid[i][j] = 0;
                }
            }
        }
        return grid[ROW-1][COL-1];
    }
};