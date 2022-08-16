class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int ROW = grid2.size();
        int COL = grid2[0].size();
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(grid2[i][j] == 1){
                    int res = true;
                    dfs(grid1,grid2,i,j,res);
                    count+=res;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j,int& res){
        if(i < 0 or j < 0 or i >= grid2.size() or j >= grid2[0].size() or grid2[i][j] == 0){
            return;
        }
        if(grid1[i][j] == 0 and grid2[i][j] == 1){
            res = false;
        }
        grid2[i][j] = 0;
        dfs(grid1,grid2,i+1,j,res);
        dfs(grid1,grid2,i-1,j,res);
        dfs(grid1,grid2,i,j+1,res);
        dfs(grid1,grid2,i,j-1,res);
    }
};

// [[1,1,1,1,0,0]
// ,[1,1,0,1,0,0]
// ,[1,0,0,1,1,1]
// ,[1,1,1,0,0,1]
// ,[1,1,1,1,1,0]
// ,[1,0,1,0,1,0]
// ,[0,1,1,1,0,1]
// ,[1,0,0,0,1,1]
// ,[1,0,0,0,1,0]
// ,[1,1,1,1,1,0]]

// [[1,1,1,1,0,1]
// ,[0,0,1,0,1,0]
// ,[1,1,1,1,1,1]
// ,[0,1,1,1,1,1]
// ,[1,1,1,0,1,0]
// ,[0,1,1,1,1,1]
// ,[1,1,0,1,1,1]
// ,[1,0,0,1,0,1]
// ,[1,1,1,1,1,1]
// ,[1,0,0,1,0,0]]