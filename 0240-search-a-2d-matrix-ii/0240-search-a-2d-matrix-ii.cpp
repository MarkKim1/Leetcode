class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = 0;
        while(true){
            if(min(row,col) < 0 || row >= matrix.size() || col >= matrix[0].size()){
                return false;
            }
            if(matrix[row][col] == target){
                return true;
            }
            if(target > matrix[row][col]){
                col++;
            }
            else if(target < matrix[row][col]){
                row--;
            }
        }
        return false;
    }
};