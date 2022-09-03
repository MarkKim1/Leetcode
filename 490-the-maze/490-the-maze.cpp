class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& des) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
        q.push(make_pair(start[0],start[1]));
        visited[start[0]][start[1]] = true;
        vector<pair<int,int>> dics = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto pos = q.front();
            q.pop();
            if(des[0] == pos.first and des[1] == pos.second){
                return true;
            }
            for(auto dic : dics){
                int row = pos.first + dic.first;
                int col = pos.second + dic.second;
                while(row >= 0 and col >= 0 and row < maze.size() and col < maze[0].size() and maze[row][col] == 0){
                    row+=dic.first;
                    col+=dic.second;
                }
                if(!visited[row-dic.first][col-dic.second]){
                    q.push(make_pair(row-dic.first,col-dic.second));
                    visited[row-dic.first][col-dic.second] = true;
                }
            }
        }
        return false;
    }
};