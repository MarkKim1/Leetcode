class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int row;
        while(top < bottom){
            int mid = (top + bottom) / 2;
            if(matrix[mid][matrix[0].size() - 1] == target) return true;
            if(matrix[mid][matrix[0].size() - 1] < target){
                top = mid + 1;
            }else{
                bottom = mid;
            }
            if(matrix[mid][matrix[0].size() - 1] < target){
                row = mid + 1;
            }else{
                row = mid;
            }
        }
        int left = 0;
        int right = matrix[0].size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
};