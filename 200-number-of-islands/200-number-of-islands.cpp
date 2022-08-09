class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]=='1'){
                    DFS(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void DFS(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1'){
            return;
        }
        grid[row][col] = '0';
        DFS(grid,row-1,col);
        DFS(grid,row+1,col);
        DFS(grid,row,col+1);
        DFS(grid,row,col-1);
    }
};