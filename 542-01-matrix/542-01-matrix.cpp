class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> result(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<int> x = {0,1,0,-1};
        vector<int> y = {1,0,-1,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int new_row = it.first + x[i];
                int new_col = it.second + y[i];
                if(new_row >= 0 and new_col >= 0 and new_row < row and new_col < col){
                    if(result[new_row][new_col] > result[it.first][it.second]+1){
                        result[new_row][new_col] = result[it.first][it.second] + 1;
                        q.push(make_pair(new_row,new_col));
                    }
                }
            }
        }
        return result;
    }
};