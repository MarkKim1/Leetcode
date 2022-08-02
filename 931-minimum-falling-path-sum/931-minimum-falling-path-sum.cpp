class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size()==1) return matrix[0][0];
        int result = INT_MAX;
        int ans = INT_MAX;
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(j == 0){
                    result = min(matrix[i][j]+matrix[i-1][j],matrix[i][j]+matrix[i-1][j+1]);
                    matrix[i][j] = result;
                    result = INT_MAX;
                    if(i == matrix.size()-1){
                        ans = min(ans,matrix[i][j]);
                    }
                }else if(j == matrix[i].size()-1){
                    result = min(matrix[i][j]+matrix[i-1][j],matrix[i][j]+matrix[i-1][j-1]);
                    matrix[i][j] = result;
                    result = INT_MAX;
                    if(i == matrix.size()-1){
                        ans = min(ans,matrix[i][j]);
                    }
                }else{
                    result = min(matrix[i][j]+matrix[i-1][j+1],min(matrix[i][j]+matrix[i-1][j-1],matrix[i][j]+matrix[i-1][j]));
                    matrix[i][j] = result;
                    result = INT_MAX;
                    if(i == matrix.size()-1){
                        ans = min(ans,matrix[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};