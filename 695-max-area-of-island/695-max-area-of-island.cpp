class Solution {
    public:
    int DFS(vector<vector<int>>&grid,int n, int m,int y, int x,int count){
        if(n <= -1 || n >= y || m <= -1 || m >= x){
            return count;
        }
        else if(grid[n][m] == 1){
            grid[n][m] = 0;
            count ++;
            count =DFS(grid,n-1,m,y,x,count);
            count =DFS(grid,n+1,m,y,x,count);
            count =DFS(grid,n,m-1,y,x,count);
            count =DFS(grid,n,m+1,y,x,count);
            
        }
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int y = grid.size();
        const int x = grid[0].size();
        int n = y;
        int m = x;
        int max = 0;
        int count = 0;
        int result = 0;
        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                if(grid[i][j] == 1){
                    cout << "found: 1 " << i << j;
                    result = DFS(grid,i,j,y,x,count);
                    cout <<" "<<result <<endl;
                    if(max <= result){
                        max = result;
                    }
                }
            }
        }
        return max;
    }
};