class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        int row = matrix.size();
        int col = matrix[0].size();
        int up = 0,right = col,down = row,left = 0;
        int current_state = 0;
        while(result.size() < col*row){
            for(int i = up; i < right; i++){
                if(visited[up][i]){
                    break;
                }
                visited[up][i] = true;
                result.push_back(matrix[up][i]);
            }
            for(int i = up+1; i < down; i++){
                if(visited[i][right-1]){
                    break;
                }
                visited[i][right-1] = true;
                result.push_back(matrix[i][right-1]);
            }
            for(int i = right-1; i >= left+1; i--){
                if(visited[down-1][i-1]){
                    break;
                }
                visited[down-1][i-1] = true;
                result.push_back(matrix[down-1][i-1]);
            }
            for(int i = down-2; i >= up+1; i--){
                if(visited[i][left]){
                    break;
                }
                visited[i][left] = true;
                result.push_back(matrix[i][left]);
            }
            up++;
            right--;
            down--;
            left++;
            
        }
        return result;
    }
};