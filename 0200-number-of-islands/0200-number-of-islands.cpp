class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i,j);
                    result++;
                }
            }
        }
        return result;
    }
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>> q;
        vector<int> offset = {0,1,0,-1,0};
        q.push(make_pair(i,j));

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            grid[row][col] = '0';
            for(int i = 0; i < offset.size()-1; i++){
                int newrow = row + offset[i];
                int newcol = col + offset[i + 1];
                if(min(newrow,newcol) >= 0 and newrow < grid.size() and newcol < grid[0].size() and grid[newrow][newcol] == '1'){
                    grid[newrow][newcol] = '0';
                    q.push(make_pair(newrow, newcol));
                }
            }
        }
    }
};