class Solution {
public:
    int result = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int count = 0;
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);
                    count = max(count,result);
                    result = 0;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() and grid[i][j] == 1){
            grid[i][j] = 0;
            result++;
            dfs(grid,i+1,j);
            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
        }
    }
};