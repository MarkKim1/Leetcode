class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> x = {1,0,-1,0};
        vector<int> y = {0,1,0,-1};
        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0],entrance[1]},0});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                int row = curr.first.first;
                int col = curr.first.second;
                int distance = curr.second;
                maze[row][col] = '+';
                if((row != entrance[0] || col != entrance[1]) && (row == 0 || row == maze.size()-1 || col == 0 || col == maze[0].size()-1)){
                    return distance;
                }
                for(int i = 0; i < 4; i++){
                    int nextrow = row + x[i];
                    int nextcol = col + y[i];
                    if(min(nextrow,nextcol) >= 0 && nextrow < maze.size() && nextcol < maze[0].size() && maze[nextrow][nextcol] != '+'){
                        maze[nextrow][nextcol] = '+';
                        q.push({{nextrow,nextcol},distance + 1});
                    }
                }
            }
        }
        return -1;
    }
};