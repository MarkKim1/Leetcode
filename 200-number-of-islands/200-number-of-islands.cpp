class Solution {
public:
    bool DFS(vector<vector<char>>&grid,int i, int j){
        if(i < 0 || i > grid.size()-1 || j < 0 || j > grid[0].size()-1){
            return false;
        }
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            DFS(grid,i-1,j);
            DFS(grid,i+1,j);
            DFS(grid,i,j-1);
            DFS(grid,i,j+1);
            return true;
        }
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    if(DFS(grid,i,j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};