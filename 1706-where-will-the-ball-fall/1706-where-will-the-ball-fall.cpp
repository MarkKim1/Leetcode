class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(),0);
        for(int i = 0; i < grid[0].size(); i++){
            ans[i] = helper(grid,0,i);
        }
        return ans;
    }
    int helper(vector<vector<int>>& grid, int row, int col){
        if(row == grid.size()) return col;
        int nextCol = col + grid[row][col];
        if(nextCol < 0 || nextCol >= grid[0].size() || grid[row][col] != grid[row][nextCol]){
            return -1;
        }
        return helper(grid,row+1,nextCol);
    }
};