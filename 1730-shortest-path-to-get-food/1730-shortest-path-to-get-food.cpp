class Solution {
public:
    int dx[4] = {0, 1, 0, -1} , dy[4] = {1, 0, -1, 0};
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size();
        queue<pair<int, int>> queue;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == '*') 
                {
                    queue.push({i, j});
                    break;
                }
            }
        }
        int res = 0 ;
        while(!queue.empty())
        {
            int size = queue.size();
            res++;
            for(int i = 0 ; i < size ; i++)
            {
                auto curr = queue.front(); queue.pop();
                int x = curr.first, y = curr.second;
                for(int d = 0 ; d < 4 ; d++)
                {
                    int dX = x + dx[d];
                    int dY = y + dy[d];
                    if(dX < 0 || dX > m-1 || dY < 0 || dY > n-1 || grid[dX][dY] == 'X') continue;
                    if(grid[dX][dY] == '#') return res;
                    grid[dX][dY] = 'X';
                    queue.push({dX,dY});
                }
            }
        }
        return -1;
    }
};