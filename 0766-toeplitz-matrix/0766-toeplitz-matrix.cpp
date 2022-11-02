class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(i+1 < matrix.size() and j+1 < matrix[0].size()){
                    if(matrix[i][j] != matrix[i+1][j+1]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};