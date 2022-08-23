class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int up = 0;
        int left = 0;
        int right = col-1;
        int down = row-1;
        vector<int> result;
        vector<vector<int>> visited(matrix.size(),vector<int>(matrix[0].size(),-1));
        while(result.size() < row*col){
            //Traverse from left to right
            for(int col = left; col <= right; col++){
                if(visited[up][col] == -1)
                    result.push_back(matrix[up][col]);
                visited[up][col] = 1;
            }
            //Traverse to downwards
            for(int row = up+1; row <= down; row++){
                if(visited[row][right] == -1)
                    result.push_back(matrix[row][right]);
                visited[row][right] = 1;
            }
            //Traverse from left to right
            for(int col = right-1; col >= left; col--){
                if(visited[down][col] == -1)
                    result.push_back(matrix[down][col]);
                visited[down][col] = 1;
            }
            //Traverse to upwards
            for(int row = down-1; row > up; row--){
                if(visited[row][left] == -1)
                    result.push_back(matrix[row][left]);
                visited[row][left] = 1;
            }
            up++;
            left++;
            right--;
            down--;
        }
        return result;
    }
};