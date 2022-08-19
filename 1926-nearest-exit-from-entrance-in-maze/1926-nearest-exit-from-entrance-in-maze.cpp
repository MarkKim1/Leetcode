class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ROW = maze.size();
        int COL = maze[0].size();
        vector<int> x = {0,1,0,-1};
        vector<int> y = {1,0,-1,0};
        queue<pair<int,pair<int,int>>> q;
        q.push(make_pair(0,make_pair(entrance[0],entrance[1])));
        int result = INT_MAX;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i = 0; i < x.size();i++){
                int row = it.second.first + x[i];
                int col = it.second.second + y[i];
                int a = it.first;
                if(min(row,col) >= 0 and row < ROW and col < COL){
                    if(maze[row][col] == '.'){
                        q.push({a+1,{row,col}});
                        maze[row][col] = '+';
                        if(row == 0 || col == 0 || row == ROW-1 || col == COL-1){
                            result = min(result,a+1);
                        }
                        maze[it.second.first][it.second.second] = '+';
                    }
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};