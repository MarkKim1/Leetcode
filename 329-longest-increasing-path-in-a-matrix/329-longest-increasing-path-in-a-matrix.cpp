class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> cache(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = INT_MIN;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans,DFS(matrix,i,j,cache));
            }
        }
        return ans;
    }
    int DFS(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>& cache){
        if(cache[i][j] != 0) return cache[i][j];
        for(auto direction : directions){
            int x = i + direction.first;
            int y = j + direction.second;
            if(min(x,y) >= 0 and x < matrix.size() and y < matrix[0].size() and matrix[x][y] > matrix[i][j]){
                cache[i][j] = max(cache[i][j],DFS(matrix,x,y,cache));
            }
        }
        return ++cache[i][j];
    }
};