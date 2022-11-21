class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> row = {1,0,-1,0};
        vector<int> col = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                maze[x][y] = '+';
                if(count != 0 and (x == 0 || y == 0 || x == maze.size()-1
                                  || y == maze[0].size()-1)){
                    return count;
                }
                for(int i = 0; i < 4; i++){
                    int next_x = x + row[i];
                    int next_y = y + col[i];
                    if(min(next_x,next_y) >= 0 and next_x < maze.size() and
                      next_y < maze[0].size() and maze[next_x][next_y] != '+'){
                        maze[next_x][next_y] = '+';
                        q.push({next_x,next_y});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
 // ["+","0","+","+","+","+","+"],
 // ["+","0","+","0","0","0","+"],
 // ["+","0","+","0","+","0","+"],
 // ["+","0","0","0","+","0","+"],
 // ["+","+","+","+","+","0","+"]
