class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bot = matrix.size()-1;
        int end = matrix[0].size()-1;
        while(top <= bot){
            int mid = (top + bot) / 2;
            if(target < matrix[mid][0]){
                bot = mid-1;
            }else if(target > matrix[mid][end]){
                top = mid+1;
            }else{
                break;
            }
        }
        if(!(top <= bot)){
            return false;
        }
        int row = (top + bot) / 2;
        int left = 0,right = matrix[0].size();
        while(left <= right){
            int mid = (right + left) / 2;
            if(target < matrix[row][mid]) {
                right = mid-1;
            }else if(target > matrix[row][mid]){
                left = mid + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};