class Solution {
    vector<vector<int>> directions = 
        {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] != 0|| grid[grid.size()-1][grid[0].size()-1] != 0){
            return -1;
        }
        
        queue<pair<int,int>> q;
        grid[0][0] = 1;
        q.push(make_pair(0,0));
        
        while(!(q.empty())){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            int distance = grid[row][col];
            if(row == grid.size()-1 && col == grid[0].size()-1){
                return distance;
            }
            for(auto neighbour: getNeighbours(row,col,grid)){
                int neighbourRow = neighbour.first;
                int neighborCol = neighbour.second;
                q.push(make_pair(neighbourRow,neighborCol));
                grid[neighbourRow][neighborCol] = distance + 1;
            }
        }
        return -1;
    }
    vector<pair<int,int>> getNeighbours(int row,int col,vector<vector<int>>&grid){
        vector<pair<int,int>> neighbours;
        for(int i = 0; i < directions.size(); i++){
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if(newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size()
              || grid[newRow][newCol] != 0){
                continue;
            }
            neighbours.push_back(make_pair(newRow,newCol));
        }
        return neighbours;
    }
    
};