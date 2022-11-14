class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(isalpha(grid[i][j])){
                    if(bfs(grid,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool bfs(vector<vector<char>>& grid, int i, int j, int count){
        vector<int> x = {0,1,0,-1};
        vector<int> y = {1,0,-1,0};
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        char source = grid[i][j];
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                int row = curr.first;
                int col = curr.second;
                q.pop();
                if(!q.empty() and row == q.front().first and col == q.front().second){
                    return true;
                }
                grid[row][col] = '#';
                for(int i = 0; i < 4; i++){
                    int newrow = row + x[i];
                    int newcol = col + y[i];
                    if(min(newrow,newcol) >= 0 and newrow < grid.size() and newcol < grid[0].size() and grid[newrow][newcol] == source){
                        q.push(make_pair(newrow,newcol));
                    }
                }
            }
        }
        return false;
    }
};