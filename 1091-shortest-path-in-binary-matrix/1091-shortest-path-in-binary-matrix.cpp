class Solution {
public:
    vector<int> x = {-1,-1,-1, 0,0, 1,1,1};
    vector<int> y = {-1, 0, 1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        grid[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int i,j;
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int n = 0; n < x.size(); n++){
                int new_row = i + x[n];
                int new_col = j + y[n];
                if(new_row >= 0 and new_col >= 0 and new_row < grid.size() and new_col < grid[0].size()){
                    if(grid[new_row][new_col] == 0){
                        grid[new_row][new_col] = grid[i][j] + 1;
                        q.push({new_row,new_col});
                    }
                }
            }
        }
        if(grid.size() > 1 and grid[grid.size()-1][grid[0].size()-1] < 2) return -1;
        return grid[grid.size()-1][grid[0].size()-1];
    }
};