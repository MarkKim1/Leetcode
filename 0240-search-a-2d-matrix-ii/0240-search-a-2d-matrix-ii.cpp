class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size()-1;
        int COL = 0;
        while(true){
            if(min(ROW,COL) < 0 || ROW >= matrix.size() || COL >= matrix[0].size()){
                return false;
            }
            if(target == matrix[ROW][COL]){
                return true;
            }
            if(target > matrix[ROW][COL]){
                COL++;
            }else{
                ROW--;
            }
        }
        return false;
    }
};