class Solution {
public:
    int count = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int result = 0;
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(i == 0 || j == 0 || i == ROW-1 || j == COL-1){
                    if(grid[i][j] == 1){
                        grid[i][j] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(i != 0 || j != 0 || i != ROW-1 || j != COL-1){
                    if(grid[i][j] == 1){
                        if(dfs(grid,i,j)){
                            result +=count;
                        }
                    }
                }
                count = 0;
            }
        }
        return result;
    }
    bool dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return true;
        }
        if(grid[i][j] == 3) return true;
        if(grid[i][j] == 2) return false;
        count++;
        grid[i][j] = 3;
        bool d1 = dfs(grid,i+1,j);
        bool d2 = dfs(grid,i-1,j);
        bool d3 = dfs(grid,i,j+1);
        bool d4 = dfs(grid,i,j-1);
        return d1 and d2 and d3 and d4;
        
    }
};