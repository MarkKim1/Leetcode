class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(),0);
        for(int col = 0; col < grid[0].size(); col++){
            int currentCol = col;
            for(int row = 0; row < grid.size(); row++){
                int nextCol = currentCol + grid[row][currentCol];
                if(nextCol < 0 || nextCol >= grid[0].size() || grid[row][currentCol] != grid[row][nextCol]){
                    ans[col] = -1;
                    break;
                }
                ans[col] = nextCol;
                currentCol = nextCol;
            }
        }
        return ans;
    }
};