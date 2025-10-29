class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    mark(grid,i,j);
                }
            }
        }
        return ans;
    }
    void mark(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        int offsets[] = {0,1,0,-1,0};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int row = curr.first + offsets[i];
                int col = curr.second + offsets[i + 1];
                if(min(row,col) >= 0 and row < grid.size() and col < grid[0].size() and grid[row][col] == '1'){
                    q.push({row,col});
                    grid[row][col] = '0';
                }                
            }
        }
    }
};