class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '*'){
                    q.push({i,{j,0}});
                    break;
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto dir : directions){
                int row = curr.first + dir[0];
                int col = curr.second.first + dir[1];
                int count = curr.second.second;
                if(min(row,col) >= 0 and row < grid.size() and col < grid[0].size() and grid[row][col] != 'X'){
                    if(grid[row][col] == '#'){
                        return count+1;
                    }
                    if(grid[row][col] != '@'){
                        q.push({row,{col,count+1}});
                        grid[row][col] = '@';
                    }
                }
            }
            grid[curr.first][curr.second.first] = 'X';
        }
        return -1;
    }
};