class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minCount = -1;
        int orangeCount = 0;
        vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    orangeCount++;
                }
                else if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
            }
        }
        q.push({-1,-1});
        
        while(!q.empty()){
            pair<int,int> temp = q.front();
            int row = temp.first;
            int col = temp.second;
            q.pop();
            if(temp.first == -1){
                minCount++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
            }
            for(int i = 0; i < directions.size(); i++){
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];
                if(newRow < 0 || newCol < 0 ||
                   newRow >= grid.size() || newCol >= grid[0].size()){
                    continue;
                }
                if(grid[newRow][newCol] == 1){
                    grid[newRow][newCol] = 2;
                    orangeCount--;
                    q.push({newRow,newCol});
                }
            }
            
        }
        return orangeCount == 0 ? minCount : -1;
    }
};

