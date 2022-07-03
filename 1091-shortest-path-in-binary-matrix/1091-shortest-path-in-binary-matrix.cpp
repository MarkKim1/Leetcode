class Solution {
public:
    vector<vector<int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0 || grid[grid.size()-1][grid[0].size()-1] != 0){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        grid[0][0] = 1;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(auto neighbor: neighbors(row,col,grid)){
                int newRow = neighbor.first;
                int newCol = neighbor.second;
                grid[newRow][newCol] = grid[row][col] + 1;
                q.push(make_pair(newRow,newCol));
            }
        }
        if(grid[grid.size()-1][grid[0].size()-1] != 0){
            return grid[grid.size()-1][grid[0].size()-1];
        }else{
            return -1;
        }
    }
    vector<pair<int,int>> neighbors(int row,int col, vector<vector<int>>& grid){
        vector<pair<int,int>> result;
        for(int i = 0; i < directions.size(); i++){
            if(row + directions[i][0] < 0 || col + directions[i][1] < 0 || row + directions[i][0] >= grid.size() || col + directions[i][1] >= grid[0].size()){
                continue;
            }
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if(grid[newRow][newCol] == 0){
                result.push_back(make_pair(newRow,newCol));
            }
        }
        return result;
    }
    
};