class Solution {
public:
    queue<pair<int,int>> q;
    int shortestBridge(vector<vector<int>>& grid) {
        for(int i = 0,found = 0; !found and i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    found = dfs(grid,i,j);
                    break;
                }
            }
        }
        int start = 2;
        vector<int> x = {0,1,0,-1};
        vector<int> y = {1,0,-1,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            // if(grid[it.first+1][it.second] == start || grid[it.first-1][it.second] == start || grid[it.first][it.second+1] == start
            //    || grid[it.first][it.second-1] == start){
            //     continue;
            // }
            for(int i = 0; i < 4; i++){
                int row = it.first + x[i];
                int col = it.second + y[i];
                
                if(min(row,col) >= 0 and max(row,col) < grid.size()){
                    if(grid[row][col] == 1){
                        return grid[it.first][it.second]-2;
                    }
                    else if(grid[row][col] == 0){
                        grid[row][col] = grid[it.first][it.second] + 1;
                        q.push({row,col});
                    }
                }
            }
        }
        return 0;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(min(i,j) < 0 || max(i,j) == grid.size() || grid[i][j] != 1){
            return 0;
        }
        q.push({i,j});
        grid[i][j] = 2;
        return 1 + dfs(grid,i+1,j) + dfs(grid,i-1,j) + dfs(grid,i,j+1) + dfs(grid,i,j-1);
    }
};