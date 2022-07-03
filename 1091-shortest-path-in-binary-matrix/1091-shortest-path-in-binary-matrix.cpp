class Solution {
public:
    int n;
    int dx[8]={-1,0,1,1,1,0,-1,-1};
    int dy[8]={-1,-1,-1,0,1,1,1,0};
    bool valid(int x,int y,vector<vector<int>>& grid)
    {
        if(x<0 || y<0 || x>=n || y>=n || grid[x][y] != 0) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>>q;
        bool reached = false;
        if(grid[0][0]==0) q.push({0,0});
        int dist = 0,x,y;
        while(!reached && !q.empty())
        {
            int size = q.size();
            dist++;
            for(int i=0;i<size;i++)
            {
                auto [x,y] = q.front();
                q.pop();
                if(x==n-1 && y==n-1)
                {
                    reached = true;
                    break;
                }
                for(int ind=0;ind<8;ind++)
                {
                    if(valid(x+dx[ind],y+dy[ind],grid))
                    {
                        q.push({x+dx[ind],y+dy[ind]});
                        grid[x+dx[ind]][y+dy[ind]] = 2;
                    }
                }
            }
        }
        if(reached) return dist;
        return -1;
    }
};