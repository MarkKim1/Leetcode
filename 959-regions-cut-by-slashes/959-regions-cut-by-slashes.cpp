class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(3*n,vector<int>(3*n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    g[3*i][3*j+2] = g[3*i+1][3*j+1] = g[3*i+2][3*j] = 1;
                }
                if(grid[i][j] == '\\'){
                    g[3*i][3*j] = g[3*i+1][3*j+1] = g[3*i+2][3*j+2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                if(g[i][j] == 0)
                    ans += dfs(g,i,j) ? 1 : 0;
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& g, int i, int j){
        if(min(i,j) < 0 || max(i,j) >= g.size() || g[i][j] != 0){
            return 0;
        }
        g[i][j] = 1;
        return 1 + dfs(g,i+1,j) + dfs(g,i-1,j) + dfs(g,i,j+1) + dfs(g,i,j-1);
    }
};