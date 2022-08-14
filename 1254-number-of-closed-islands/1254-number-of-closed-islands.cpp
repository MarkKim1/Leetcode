class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int count = 0;
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(grid[i][j] == 0){
                    if(i == 0 or j == 0 or i == ROW-1 or j == COL-1){
                        grid[i][j] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(grid[i][j] == 0){
                        if(dfs(grid,i,j)){
                            count++;
                        }
                    }
                }
            }
        return count;
    }
    bool dfs(vector<vector<int>>& grid, int i, int j){
        if(grid[i][j] == 3) return true;
        if(grid[i][j] == 2) return false;
        if(grid[i][j] == 1) return true;
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size()){
            return false;
        }
        if(grid[i][j] == 0){
            grid[i][j] = 3;
        }
        bool d1 = dfs(grid,i+1,j);
        bool d2 = dfs(grid,i-1,j);
        bool d3 = dfs(grid,i,j+1); 
        bool d4 = dfs(grid,i,j-1);
        return d1 and d2 and d3 and d4;
    }
};