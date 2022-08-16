class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q,q1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    q.push({i+1,j});
                    q.push({i-1,j});
                    q.push({i,j+1});
                    q.push({i,j-1});
                }
            }
        }
        int step = 0;
        
        while(!q.empty()){
            step++;
            while(!q.empty()){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() and grid[i][j] == 0){
                    grid[i][j] = step;
                    q1.push({i+1,j});
                    q1.push({i-1,j});
                    q1.push({i,j+1});
                    q1.push({i,j-1});
                }
            }
            swap(q1,q);
        }
        return step == 1 ? -1 : step-1;
    }
};